#ifndef GET_PID_INFO_H
# define GET_PID_INFO_H

enum	get_pid_info_status {
	SUCCESS,
	ERR_CHILD_ARRAY_TOO_SMALL,
	ERR_UNKNOWN, //currently not used
};

struct pid_info {
	pid_t			     pid;
	long			     state;
	void			    *stack;
	u64			     age;   //Not sure about this
	pid_t __user		     *child_array;   //where is max child ?
	size_t			     child_array_size;
	enum get_pid_info_status     syscall_status;
	pid_t			     parent_pid;
	char			     root_path[PATH_MAX];
	char			     cwd[PATH_MAX];
};

long	sys_get_pid_info(struct pid_info __user *ret, int pid); // int or long return ?

#endif
