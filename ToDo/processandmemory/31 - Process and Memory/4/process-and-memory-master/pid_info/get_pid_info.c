#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/syscalls.h>
#include <linux/fs.h>
#include <linux/pid.h>
#include <linux/uaccess.h>
#include <linux/path.h>
#include <linux/kernel.h>
#include <linux/string.h>
#include <linux/dcache.h>
#include <linux/slab.h>
#include <linux/fs_struct.h>
#include <linux/list.h>

struct pid_info {
	char		name[TASK_COMM_LEN];
	pid_t		pid;	
	pid_t		parent;
	void 		*stack;
	long		state;
	u64		start_time;
	size_t		s_child;
	pid_t		*children;
	size_t		s_root;
	char		*root;
	size_t		s_pwd;
	char		*pwd;
};

SYSCALL_DEFINE2(get_pid_info, struct pid_info __user *, info, int, pid)
{
	ssize_t			retval = 0;
	struct pid		*p;
	struct task_struct	*task;
	struct task_struct	*child;
	char			buff[PATH_MAX + 1];
	char			comm[TASK_COMM_LEN];
	char			*path; 
	size_t			usize = 0;
	size_t			ksize = 0;
	size_t			i = 0;

	p = find_get_pid(pid);
	if (!(task = pid_task(p, PIDTYPE_PID))) {
		retval = -ESRCH;
		goto out;
	}

	if (task->parent) {
		if ((copy_to_user(&info->parent, &task->parent->pid, sizeof(pid_t)))) {
		 	retval = -EFAULT;
			goto out;
		}
	}

	if ((copy_to_user(&info->pid, &task->pid, sizeof(pid_t)))) {
		retval = -EFAULT;
		goto out;
	}

	if ((copy_to_user(&info->stack, &task->stack, sizeof(int)))) {
		retval = -EFAULT;
		goto out;
	}

	if ((copy_to_user(&info->state, &task->state, sizeof(long)))) {
		retval = -EFAULT;
		goto out;
	}
	
	if (copy_to_user(&info->start_time, &task->start_time, sizeof(u64))) {
		retval = -EFAULT;
		goto out;
	}

	memset(comm, 0, TASK_COMM_LEN);	
	get_task_comm(comm, task);
	if (copy_to_user(info->name, comm, strlen(comm)))
		goto err;

	if (copy_from_user(&usize, &info->s_child, sizeof(size_t)))
		goto err;
	task_lock(task);
	list_for_each_entry(child, &task->children, sibling) {
		if (i > usize) {
			i = 0;
			child = NULL;
			list_for_each_entry(child, &task->children, sibling)
				i++;
			task_unlock(task);
			if (copy_to_user(&info->s_child, &i, sizeof(size_t)))
				goto err;
			goto too_small;
		}
		else if (copy_to_user(&info->children[i], &child->pid, sizeof(pid_t))) {
			task_unlock(task);
			goto err;
		}
		i++;
	}
	task_unlock(task);

	if (copy_from_user(&usize, &info->s_root, sizeof(size_t)))
		goto err;
	memset(buff, 0, PATH_MAX + 1);
	task_lock(task);
	path = dentry_path_raw(task->fs->root.dentry, buff, PATH_MAX + 1);
	task_unlock(task);
	ksize = strlen(path);
	if (ksize > usize) {
		if (copy_to_user(&info->s_root, &ksize, sizeof(size_t)))
			goto err;
		goto too_small;
	}
	else if (copy_to_user(info->root, path, ksize))
		goto err;

	if (copy_from_user(&usize, &info->s_pwd, sizeof(size_t)))
		goto err;
	memset(buff, 0, PATH_MAX + 1);
	task_lock(task);
	path = dentry_path_raw(task->fs->pwd.dentry, buff, PATH_MAX + 1);
	task_unlock(task);
	ksize = strlen(path);
	if (ksize > usize) {
		if (copy_to_user(&info->s_pwd, &ksize, sizeof(size_t)))
			goto err;
		goto too_small;
	}
	else if (copy_to_user(info->pwd, path, ksize))
		goto err;

	return retval;
out:
	return retval;

err:
	retval = -EFAULT;
	return retval;

too_small:
	retval = -ENOMEM;
	return retval;
}
