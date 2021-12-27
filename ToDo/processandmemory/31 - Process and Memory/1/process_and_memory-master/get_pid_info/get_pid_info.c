#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/pid.h>
#include <linux/fs_struct.h>
#include <linux/slab.h>

#include "get_pid_info.h"

static void	get_children(struct task_struct *task_pid, int *children)
{
	struct task_struct *child = NULL;
	int i = 0;

	list_for_each_entry(child, &task_pid->children, sibling)
	{
		if (i == CHILD_MAX)
			goto warn;
		children[i++] = task_pid_vnr(child);
	}
	return ;
warn:
	pr_warning("get_pid_info: Too many children, stopped at CHILD_MAX\n");
}

SYSCALL_DEFINE2(get_pid_info, struct pid_info __user*, retinfo, int, pid)
{
	struct pid_info *tmp;
	struct pid *pid_struct;
	struct task_struct *task_pid;
	struct path pwd, root;
	char *dtmp, *buf;

	pid_struct = find_get_pid(pid);
	if (!pid_struct)
		return -ESRCH;
	task_pid = get_pid_task(pid_struct, PIDTYPE_PID);
	if (!task_pid)
		return -EFAULT;
	tmp = kmalloc(sizeof(struct pid_info), GFP_KERNEL);
	if (!tmp)
		return -ENOMEM;
	tmp->pid = task_pid_vnr(task_pid);
	tmp->parent_pid = task_pid_vnr(task_pid->real_parent);
	tmp->state = task_pid->state;
	tmp->age = task_pid->start_time;
	tmp->stack = task_pid->stack;
	get_fs_root(task_pid->fs, &root);
	get_fs_pwd(task_pid->fs, &pwd);
	buf = kmalloc(PATH_MAX, GFP_KERNEL);
	if (!buf)
		return -ENOMEM;
	memset(tmp->children, 0, sizeof(tmp->children));
	dtmp = dentry_path_raw(root.dentry, buf, PATH_MAX);
	strcpy(tmp->root_path, dtmp);
	dtmp = dentry_path_raw(pwd.dentry, buf, PATH_MAX);
	strcpy(tmp->pwd_path, dtmp);
	get_children(task_pid, tmp->children);
	if (copy_to_user(retinfo, tmp, sizeof(struct pid_info)))
		return -EFAULT;
	kfree(buf);
	kfree(tmp);
	return (0);
}
