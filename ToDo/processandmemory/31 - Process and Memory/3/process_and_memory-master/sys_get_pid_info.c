// SPDX-License-Identifier: GPL-2.0
#include <linux/linkage.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/syscalls.h>
#include <linux/dcache.h>
#include <linux/slab.h>
#include <linux/fs_struct.h>
#include <linux/fdtable.h> // remove this latter
#include <linux/path.h> // remove this latter
#include <linux/file.h>
#include <linux/fs.h>
#include <linux/dcache.h>
#include <linux/sched/cputime.h>
#include <linux/timekeeping.h>
#include <asm/page.h>
#include <linux/mm.h>
#include <linux/rwsem.h>
#include <linux/anon_inodes.h>
#include <linux/mman.h>

# define LOG "get_pid_info: "

static void debug_print_kernel_stack(void *kstack, uint64_t len)
{
	static char buffer[49];
	uint64_t    i = 0;

	if (IS_ERR_OR_NULL(kstack))
		return ;
	while (i < len) {
		uint64_t    u;

		memset(buffer, ' ', 48);
		u = 0;
		while (u < 16 && u + i < len) {
			sprintf(buffer + u * 3, "%02hhx ", *(char *)(kstack + i + u));
			u++;
		}
		printk(KERN_INFO LOG "%s\n", buffer);
		i += 16;
	}
}

static int kernel_stack_mmap(struct file *file, struct vm_area_struct *vma) /* remaps the kernel stack if it is already mapped, you saw nothing. */
{
	struct task_struct *task = file->private_data;
	struct page	    *kstack = vmalloc_to_page(task->stack);

	if (IS_ERR_OR_NULL(kstack)) {
		printk(KERN_WARNING LOG "Failed to get kernel stack page struct\n");
		return -EINVAL;
	}

	if (0 != vm_insert_page(vma, vma->vm_start, kstack)) {
		printk(KERN_WARNING LOG "Failed to insert page into process' vma\n");
		return -EINVAL;
	}
	return 0;
}

static struct file_operations	get_pid_stack_fops = {
	.mmap = kernel_stack_mmap
};

static int32_t  get_user_path_from_struct_path(struct path *path, char *buffer, uint64_t size)
{
	char	*ret;

	ret = dentry_path_raw(path->dentry, buffer, size);
	if (IS_ERR(ret))
		return -1;
	memcpy(buffer, ret, size);
	return 0;
}


uint64_t    klist_len(const struct list_head *list)
{
	uint64_t	     __len = 0;
	struct list_head    *pos = NULL;

	list_for_each(pos, list) {
		__len++;
	}
	return __len;
}

static int64_t  map_kernel_stack(struct pid_info *info, struct task_struct *task)
{
	int64_t		ret;
	struct file	*stack_file;

	stack_file = anon_inode_getfile("get_pid_info_stack", &get_pid_stack_fops, task, O_RDONLY);
	printk(KERN_INFO LOG "task->stack ptr: %px, current sp: %px\n", info->stack, &info);
	if (IS_ERR_OR_NULL(stack_file)) {
		printk(KERN_WARNING LOG "Failed to get anonymous inode\n");
		ret = -EIO; // change this
		goto err;
	}
	if (!IS_ERR_OR_NULL(info->stack)) {
		printk(KERN_INFO LOG "Kernel stack of pid: %d\n", info->pid);
		/* debug_print_kernel_stack(info->stack, THREAD_SIZE); */
	}

	info->stack = vm_mmap(stack_file, 0, THREAD_SIZE * 2, PROT_READ, MAP_PRIVATE, 0);
	if (IS_ERR(info->stack)) {
		printk(KERN_WARNING LOG "Failed to vm_mmap kernel stack\n");
		ret = -EPERM;
		goto err;
	}
	printk(KERN_WARNING LOG "Kernel stack of process: %d has been mapped to %px\n", info->pid, info->stack);
	return 0;
err:
	return ret;
}

static inline long  normalize_process_state(long state)
{
	if (state > 0)
		return (1);
	else if (state < 0)
		return (-1);
	return (state);
}

static inline int64_t	fill_child_array(struct pid_info *info, struct task_struct *task)
{
	uint64_t	    required_child_array_size;
	int64_t		    ret;

	required_child_array_size = klist_len(&task->children) * sizeof(pid_t);
	info->syscall_status = SUCCESS;
	ret = 0;
	if (required_child_array_size > info->child_array_size) {
		info->child_array_size = required_child_array_size;
		info->syscall_status = ERR_CHILD_ARRAY_TOO_SMALL;
		ret = -ENOMEM;
		printk(KERN_INFO LOG "child_array was too small\n");
		goto out;
	} else {
		struct task_struct *pos = NULL;
		uint64_t	    i = 0;
		pid_t		    vpid;

		list_for_each_entry(pos, &task->children, sibling) {
			vpid = task_tgid_vnr(pos);
			if (0 != copy_to_user(&info->child_array[i], &vpid, sizeof(pid_t))) { // check return value and maybe make it a single call
				ret = -EPERM; //better error code ?
				goto out;
			}
			i++;
		}
		info->child_array_size = required_child_array_size;
	}
out:
	return ret;
}

SYSCALL_DEFINE2(get_pid_info, struct pid_info __user *, to, int, pid)
{
	struct pid_info	    *info;
	struct task_struct  *task;
	int64_t		    ret;

	printk(KERN_INFO LOG "get_pid_info() was called by pid: %d\n", current->pid);

	if (NULL == (info = kmalloc(sizeof(struct pid_info), GFP_KERNEL)) || to == NULL) {
		ret = -ENOMEM;
		goto err;
	}

	if (0 != copy_from_user(info, to, sizeof(struct pid_info))) {
		kfree(info);
		ret = -EPERM;
		goto err;
	}

	rcu_read_lock();
	if (NULL == (task = find_task_by_pid_ns(pid, task_active_pid_ns(current)))) {
		ret = -ESRCH;
		goto err;
	}
	ret = 0;

 	rcu_read_unlock();
	get_task_struct(task);
	task_lock(task);
	info->pid = task_tgid_vnr(task);
	if (info->pid == 0 && pid != 0) {
		printk(KERN_INFO LOG "Task corresponding to pid: %d is already dead\n", pid);
		ret = -ESRCH;
		goto err_tlock_held_need_kfree;
	}

	info->state = normalize_process_state(task->state);

	info->stack = task->stack;
	ret = map_kernel_stack(info, task);
	if (0 != ret) {
		printk(KERN_INFO LOG "Failed to map kernel_stack of process: %d into userspace\n", info->pid);
		goto err_tlock_held_need_kfree;
	}


	info->age = ktime_get_ns() - task->start_time;
	printk(KERN_INFO LOG "age in seconds = %llu, remaining age in ns = %llu\n", info->age / NSEC_PER_SEC, info->age % NSEC_PER_SEC);

	// Need to reacquire rcu lock for dereferencing the __rcu protected real_parent member
	rcu_read_lock();
	info->parent_pid = task_tgid_vnr(rcu_dereference(task->real_parent));
	rcu_read_unlock();

	ret = get_user_path_from_struct_path(&task->fs->root, info->root_path, sizeof(info->root_path));
	ret |= get_user_path_from_struct_path(&task->fs->pwd, info->cwd, sizeof(info->cwd));
	if (ret != 0) {
		ret = -EPERM;
		goto err_tlock_held_need_kfree;
	}
	ret = fill_child_array(info, task);
	if (0 != copy_to_user(to, info, sizeof(struct pid_info))) {
		ret = -EPERM;
		goto err_tlock_held_need_kfree;
	}
	if (ret != 0) /* if fill_child_array failed we need to copy_to_user anyway to propagate the error code */
		goto err_tlock_held_need_kfree;

	kfree(info);
	task_unlock(task);
	put_task_struct(task);
	return ret;
err_tlock_held_need_kfree:
	kfree(info);
err_tlock_held:
	task_unlock(task);
	put_task_struct(task);
err:
	return ret;
}
