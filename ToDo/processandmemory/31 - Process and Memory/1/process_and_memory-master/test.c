#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <limits.h>
#include <inttypes.h>

struct pid_info {
	int pid;
	int parent_pid;
	long state;
	void const *stack;
	uint64_t age;
	int children[512];
	char root_path[PATH_MAX];
	char pwd_path[PATH_MAX];
};

int	get_pid_info(struct pid_info *ret, int pid)
{
	return syscall(335, ret, pid);
}

int	main(int ac, char **av)
{
	struct pid_info p_info;
	int ret;

	if (ac < 2)
	{
		printf("Give PID plz\n");
		return 1;
	}
	ret = get_pid_info(&p_info, atoi(av[1]));
	if (ret)
		goto err;
	printf("PID = %d\n", p_info.pid);
	printf("STACK = %#llx\n", p_info.stack);
	printf("STATE = %ld\n", p_info.state);
	printf("AGE = %lu\n", p_info.age);
	printf("ROOT PATH = %s\n", p_info.root_path);
	printf("PWD PATH = %s\n", p_info.pwd_path);

	printf("CHILDREN :\n");
	int i = 0;
	while (p_info.children[i])
		printf("\t%d\n", p_info.children[i++]);
/*
	if (p_info.parent_pid)
	{
		printf("PARENT :::\n");
		ret = get_pid_info(&p_info, p_info.parent_pid);
		printf("PID = %d\n", p_info.pid);
		printf("STACK = %#llx\n", p_info.stack);
		printf("STATE = %ld\n", p_info.state);
		printf("AGE = %lu\n", p_info.age);
		printf("ROOT PATH = %s\n", p_info.root_path);
		printf("PWD PATH = %s\n", p_info.pwd_path);
	}
*/
	return 0;
err:
	printf("Error\n");
	return 1;
}
