#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <limits.h>
#include <dirent.h>
#include <fcntl.h>
#include <assert.h>
#include <string.h>


#define __NR_get_pid_info 335

static void  print_stack(void *kstack, uint64_t len)
{
	static char buffer[49];
	uint64_t    i = 0;

	if (kstack == NULL)
		return ;
	while (i < len) {
		uint64_t    u;
		memset(buffer, ' ', 48);
		u = 0;
		while (u < 16 && u + i < len) {
			sprintf(buffer + u * 3, "%02hhx ", *(char *)(kstack + i + u));
			u++;
		}
		printf("%s\n", buffer);
		i += 16;
	}

}

/* Further describe the reason of error if the sys_get_pid_info fails */
enum	get_pid_info_status {
	SUCCESS,
	ERR_CHILD_ARRAY_TOO_SMALL,
	ERR_UNKNOWN, //currently not used
};

struct pid_info {
	pid_t			     pid;
	long			     state;
	void			    *stack;
	uint64_t		     age;   //Not sure about this
	pid_t			    *child_array;   //where is max child ?
	size_t			     child_array_size;
	enum get_pid_info_status     syscall_status;
	pid_t			     parent_pid;
	char			     root_path[PATH_MAX];
	char			     cwd[PATH_MAX];
};

static char tabs[128];

static void print_children_info(struct pid_info *info, uint64_t depth)
{
	uint64_t    i = 0;

	assert(info->syscall_status == SUCCESS);
	assert(sizeof(pid_t) == 4);
	memset(tabs, '\t', depth);
	tabs[depth] = '\0';
	while (i < info->child_array_size / sizeof(pid_t)) {
		printf("%sPid for child: %lu -> %u\n", tabs, i, info->child_array[i]);
		i++;
	}
}

static int get_process_name_by_pid(pid_t pid, char * const buf, const uint64_t size)
{
	static char cmdline_path[4096];
	int	    fd;
	ssize_t	    ret;

	snprintf(cmdline_path, sizeof(cmdline_path), "/proc/%u/comm", pid);
	if (-1 == (fd = open(cmdline_path, O_RDONLY))) {
		printf("Failed to open %s\n", cmdline_path);
		return (-1);
	}
	ret = read(fd, buf, size);

	if (ret == -1) {
		printf("Failed to read from %s\n", cmdline_path);
		return (-1);
	}
	buf[ret] = '\0';
	return (0);
}

static void print_pid_info(struct pid_info *info, uint64_t depth)
{
	static char name[4096];

	if (0 != get_process_name_by_pid(info->pid, name, sizeof(name))) {
		strcpy(name, "Unable to retrieve name");
	}
	memset(tabs, '\t', depth);
	tabs[depth] = '\0';
	printf("%sProcess name: %s\n", tabs, name);
	printf("%spid: %d\n%sstate:%ld\n%sstack_ptr: %p\n%sage: %lu, child_array: %p, no_children = %lu, parent_pid: %d\n%sroot_path: %s\n%scwd: %s\n",
		tabs,		info->pid,
		tabs,		info->state,
		tabs,		info->stack,
		tabs,		info->age,
				info->child_array,
				info->child_array_size / sizeof(pid_t),
				info->parent_pid,
		tabs,		info->root_path,
		tabs,		info->cwd);
	if (info->stack != NULL)
		printf("first word of kstack: %lx\n", *(long*)info->stack);
	print_stack(info->stack, 128);
}

static int32_t test_function(void)
{
	DIR		*dir;
	struct dirent	*entry;

	if (NULL == (dir = opendir(".")))
		return -1;
	while ((entry = readdir(dir)) != NULL) {
		printf("Opening: %s ->", entry->d_name);
		if (open(entry->d_name, O_RDONLY) != -1)
			printf("SUCCESS\n");
		else
			printf("FAIL\n");
	}
	/* int fds[2]; */

	/* pipe(fds); */
	return (0);
}


static int32_t	wrapper_get_pid_info(struct pid_info *info, pid_t pid) {
	uint64_t    current_array_size = 32;

	do {
		if (NULL == (info->child_array = malloc(sizeof(pid_t) * current_array_size))) {
			perror(NULL);
			exit(EXIT_FAILURE);
		}
		info->child_array_size = current_array_size * sizeof(pid_t);
		current_array_size *= 2;
		/* printf("Calling get_pid_info with child_array of size: %lu\n", info->child_array_size); */
		if (-1 == syscall(__NR_get_pid_info, info, pid))
		{
			if (info->syscall_status == ERR_CHILD_ARRAY_TOO_SMALL) {
				printf("get_pid_info informed that the child_array was too small for size: %lu\n", current_array_size);
				current_array_size *= 2;
				free(info->child_array);
				continue ;
			}
			printf("get_pid_info returned -1\n");
			free(info->child_array);
			return (-1);
		}

		return (0);
	} while (info->syscall_status != SUCCESS);
	return (0);
}

static void rec_print_pid_info(pid_t pid, uint64_t depth)
{
	struct pid_info	info;
	uint64_t	i;

	if (0 != wrapper_get_pid_info(&info, pid))
	{
		printf("Failed to call get_pid_info");
		exit(EXIT_FAILURE);
	}
	print_pid_info(&info, depth);

	i = 0;
	print_children_info(&info, depth);
	while (i < info.child_array_size / sizeof(pid_t)) {
		rec_print_pid_info(info.child_array[i], depth + 1);
		i++;
	}
	free(info.child_array);
	printf("\n");
}


#define FORK_NUMBER 4

int main(void)
{
	/* struct pid_info	info; */
	uint32_t    i = 0;

	sleep(1);
	while (i < FORK_NUMBER) {
		if (0 == fork()) {
			assert(sleep(2) == 0);
			exit(0);
		}
		i++;
	}

	(void)test_function;
	struct pid_info info;
	assert(-1 == wrapper_get_pid_info(&info, -1));
	assert(-1 == wrapper_get_pid_info(&info, -42));
	/* sleep(1); */
	/* test_function() == 0 ? printf("Test_function was successfull\n") */
	/* 	: printf("Test_function was successfull\n"); */
	/* if (-1 == wrapper_get_pid_info(&info, 1)) */
	/* 	exit(EXIT_FAILURE); */
	/* print_pid_info(&info); */
	/* rec_print_pid_info(1, 0); */
	printf("User space stack addr: %p\n", &i);
	rec_print_pid_info(1, 0);
	printf("-----KTHREADS--------\n");
	rec_print_pid_info(2, 0);
	return 0;
}
