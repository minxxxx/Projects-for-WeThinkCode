#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

# define TASK_COMM_LEN		16
# define ERSCH			"No such process"

typedef int	pid_t;

struct pid_info {
	char		name[TASK_COMM_LEN];
	pid_t		pid;
	pid_t		parent;
	void 		*stack;
	long		state;
	long unsigned	start_time;
	size_t		s_child;
	pid_t		*children;
	size_t		s_root;
	char		*root;
	size_t		s_pwd;
	char		*pwd;
};

long	get_pid_info(struct pid_info *ret, int pid) { return syscall(333, ret, pid); };

			
void	show_pid_info(int pid, size_t CHILD_SIZE, size_t  ROOT_SIZE, size_t PWD_SIZE)
{
	struct pid_info		ret;
	size_t			s_buffers[3];
	int			i = 0;
	int			r;

	if (!pid)
		return ; 
	/* doesn't check if it's size_t... */
	ret.s_child = CHILD_SIZE;
	ret.children = malloc((CHILD_SIZE + 1) * sizeof(pid_t));
	ret.s_root = ROOT_SIZE;
	ret.root = malloc(ROOT_SIZE + 1);
	ret.s_pwd = PWD_SIZE;
	ret.pwd = malloc(PWD_SIZE + 1);
	memset(ret.name, 0, TASK_COMM_LEN);
	if (ret.children && ret.root && ret.pwd) {
		while (1) {
			memset(ret.children, 0, (ret.s_child + 1) * sizeof(pid_t));
			memset(ret.root, 0, ret.s_root + 1);
			memset(ret.pwd, 0, ret.s_pwd + 1);
			s_buffers[0] = ret.s_child;
			s_buffers[1] = ret.s_root;
			s_buffers[2] = ret.s_pwd;
			if ((r = get_pid_info(&ret, pid)) == 0) {
				printf("name %s\n", ret.name);
				printf("pid %ld\n", ret.pid);
				printf("pid parent %d\n", ret.parent);
				printf("stack %p\n", ret.stack);
				printf("state %d\n", ret.state);
				while (ret.children[i])
					printf("%d\n", ret.children[i++]);
				printf("root %s\n", ret.root);
				printf("pwd %s\n", ret.pwd);
				i = 0;
				printf("\n------\n");
				while (ret.children[i])
					show_pid_info(ret.children[i++], CHILD_SIZE, ROOT_SIZE, PWD_SIZE);
				break;
			} else if (!strcmp(strerror(errno), ERSCH)) {
				printf("%s : %d\n", strerror(errno), pid);
				break;
			} else {
				printf("Pid [%d] buffers too small..., sizes needed :\n", pid);
				printf("children %ld vs %ld\n", s_buffers[0], ret.s_child);
				printf("root %ld vs %ld\n", s_buffers[1], ret.s_root);
				printf("pwd %ld vs %ld\n\n", s_buffers[2], ret.s_pwd);
				if (s_buffers[0] != ret.s_child) {
					free(ret.children);
					ret.children = malloc((ret.s_child + 1) * sizeof(pid_t));
				}
				if (s_buffers[1] != ret.s_root) {
					free(ret.root);
					ret.root = malloc(ret.s_root + 1);
				}
				if (s_buffers[2] != ret.s_pwd) {
					free(ret.pwd);
					ret.pwd = malloc(ret.s_pwd + 1);
				}
			}
		}
	} else {
		exit(1);
	}
}
	
int	main(int argc, char **argv)
{
	struct pid_info		ret;
	int			pid;	
	int			i;
	
	if (argc == 1) {
		pid = getpid();
	} else {
		pid = atoi(argv[1]);
	}
	if (argc == 1 || argc == 2)
		show_pid_info(pid, 10, 512, 512);	
	else if (argc = 5)
		show_pid_info(pid, atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
	else
		dprintf(2, "if argc >= 3, provide size_t until 5\n");
	return (0);
}
