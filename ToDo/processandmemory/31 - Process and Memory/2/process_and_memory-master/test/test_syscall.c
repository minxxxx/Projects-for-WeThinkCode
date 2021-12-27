#include <linux/pmsyscall.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

void	display_tree(pid_t pid, int depth)
{
	struct pid_info info;
	long		ret;

	ret = syscall(333, &info, pid);
	if (ret < 0) {
		printf("ERROR: Syscall errno is %d : %s\n",
			errno,
			strerror(errno));
		return ;
	}
	info.age /= 1000000000;
	printf("%8d\t%02lld:%02lld:%02lld\t%*c%s\n",
			info.pid,
			info.age / 3600, info.age / 60 % 60, info.age % 60,
			/* ??:??:?? */
			(depth + 1) * 2, ' ',
			info.name);
	if (info.children)
	{
		int child = 0;
		while (info.children[child]) {
			display_tree(info.children[child++], depth + 1);
		}
		munmap(info.children, info.mapped);
	}
}

int	display_info_of(pid_t pid)
{
	struct pid_info info;
	long		ret;

	ret = syscall(333, &info, pid);
	if (ret < 0) {
		printf("ERROR: For pid %d: Syscall errno is %d : %s\n",
			pid,
			errno,
			strerror(errno));
		return 1;
	}
	printf("syscall ret: %ld\n"
		"\tpid:\t%d\n"
		"\tparent:\t%d\n"
		"\tage:\t%llds\n"
		"\tmapped:\t%ld\n"
		"\tname:\t%p\t%s\n"
		"\troot:\t%p\t%s\n"
		"\tpwd:\t%p\t%s\n"
		"\tchildren_array:\t%p\n",
			ret,
			info.pid,
			info.parent,
			info.age / 1000000000,
			info.mapped,
			info.name, info.name,
			info.root, info.root,
			info.pwd, info.pwd,
			info.children);
	if (info.children)
	{
		int child = 0;
		do {
			printf("\t\t%d\n", info.children[child]);
		} while (info.children[child++]);
		munmap(info.children, info.mapped);
	}
	return 0;
}

int main(void)
{
	pid_t		ppid;

	ppid = getppid();
	printf("my parent pid is : %d\n", ppid);
	display_info_of(ppid);
	printf("-----------------------------\n");
	display_tree(ppid, 0);
	printf("-----------------------------\n");
	display_info_of(1);
	printf("-----------------------------\n");
	display_info_of(0);
	display_info_of(8999);
	printf("-----------------------------\n");
	display_tree(1, 0);
	return 0;
}
