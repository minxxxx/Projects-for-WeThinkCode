#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/string.h>
#include <linux/fs_struct.h>
#include <linux/timekeeping.h>
#include <uapi/linux/pmsyscall.h>
#include <uapi/asm-generic/mman-common.h>

struct pm_lengths {
	unsigned long pid_array_len;
	unsigned long name_len;
	unsigned long root_len;
	unsigned long pwd_len;
};

static struct pm_lengths compute_mapping_len(struct task_struct *ts)
{
	struct pm_lengths	l;
	int			num_children;
	struct list_head	*traverse_ptr;

	num_children = 0;
	read_lock(&tasklist_lock);
	list_for_each(traverse_ptr, &ts->children) {
		num_children++;
	}
	read_unlock(&tasklist_lock);
	l.pid_array_len = (num_children + 1) * sizeof(pid_t);
	l.name_len = TASK_COMM_LEN;
	l.root_len = PATH_MAX;
	l.pwd_len = PATH_MAX;
	return l;
}

static void *alloc_pages_for_user(struct pm_lengths l)
{
	unsigned long addr;
	unsigned long total_len = l.pid_array_len
				+ l.name_len
				+ l.root_len
				+ l.pwd_len;
	addr = sys_mmap_pgoff(0, total_len,
		PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS,
		0, 0);
	return ((void *)addr);
}

static void fill_pid_array(struct task_struct *ts, pid_t *array,
				unsigned long array_len)
{
	struct task_struct	*child;
	int			i;


	array_len /= sizeof(pid_t);
	if (array_len == 0)
		return;
	read_lock(&tasklist_lock);
	child = list_first_entry_or_null(&ts->children,
					struct task_struct, sibling);
	for (i = 0;
		i < array_len - 1 && child != NULL;
		child = list_next_entry(child, sibling)) {

		array[i++] = child->pid;
		if (list_is_last(&child->sibling, &ts->children))
			break;
	}
	array[i] = 0;
	read_unlock(&tasklist_lock);
}

SYSCALL_DEFINE2(get_pid_info, struct pid_info __user *, pid_struct, int, pid)
{
	struct pid_info		local;
	struct task_struct	*ts;
	struct pm_lengths	l;
	void			*mapping_addr;

	/* zero out user struct and check it can be written to */
	if (clear_user(pid_struct, sizeof(struct pid_info)))
		return -EFAULT;
	ts = find_task_by_vpid(pid);
	if (!ts)
		return -ESRCH;
	get_task_struct(ts);

	memset(&local, 0, sizeof(struct pid_info));
	local.pid = ts->pid;
	local.state = ts->state;
	local.age = ktime_get_ns() - ts->start_time;
	local.stack = ts->stack;
	local.parent = ts->parent->pid;

	/* Alloc the pages */
	l = compute_mapping_len(ts);
	mapping_addr = alloc_pages_for_user(l);
	if (mapping_addr != (void *)-1) {
		local.mapped = l.pid_array_len
				+ l.name_len
				+ l.root_len
				+ l.pwd_len;

		/* The pid array */
		fill_pid_array(ts, mapping_addr, l.pid_array_len);
		local.children = mapping_addr;

		/* Copy the strings */
		get_task_comm(mapping_addr + l.pid_array_len, ts);
		local.name = mapping_addr + l.pid_array_len;

		task_lock(ts);
		local.root = dentry_path_raw(ts->fs->root.dentry,
			mapping_addr + l.pid_array_len + l.name_len,
			l.root_len);

		local.pwd = dentry_path_raw(ts->fs->pwd.dentry,
			mapping_addr + l.pid_array_len + l.name_len
				+ l.root_len,
			l.pwd_len);
		task_unlock(ts);
	}

	put_task_struct(ts);

	/* Write to user ptr */
	if (copy_to_user(pid_struct, &local, sizeof(struct pid_info)))
		return -EFAULT;
	return 0;
}
