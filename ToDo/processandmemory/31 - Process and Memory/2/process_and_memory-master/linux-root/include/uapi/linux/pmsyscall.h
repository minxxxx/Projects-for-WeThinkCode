#ifndef PMSYSCALL_H
# define PMSYSCALL_H

#ifndef __KERNEL__
# include <unistd.h> /* for pid_t */
# include <stdint.h> /* for uint64_t */
#else
# include <linux/types.h> /* for pid_t */
#endif

struct pid_info {
	pid_t		pid;
	long		state;		/* -1 unrunnable, 0 runnable, >0 stopped: */
	void		*stack;
	uint64_t	age;
	pid_t		*children;	/* NUL terminated array */
	pid_t		parent;
	char		*name;
	char		*root;
	char		*pwd;
	size_t		mapped;
};

#endif
