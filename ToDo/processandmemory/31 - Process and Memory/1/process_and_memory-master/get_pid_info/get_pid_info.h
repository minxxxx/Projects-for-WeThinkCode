#ifndef GET_PID_INFO_H
#define GET_PID_INFO_H

#include <linux/limits.h>

#define CHILD_MAX 512

struct pid_info {
	int pid;
	int parent_pid;
	long state;
	void const *stack;
	uint64_t age;
	int children[CHILD_MAX];
	char root_path[PATH_MAX];
	char pwd_path[PATH_MAX];
};

#endif
