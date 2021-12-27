/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 11:16:30 by jtranchi          #+#    #+#             */
/*   Updated: 2018/08/10 11:16:32 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_strace.h"


int sigs()
{
	if (WIFEXITED(status))
		return (1);
	else if (WIFSTOPPED(status))
	{
		if (WSTOPSIG(status) != SIGTRAP)
		{
			printf("--- %s---\n", get_signal_name(WSTOPSIG(status)));
			if (WSTOPSIG(status) == SIGSEGV)
				return (1);
			//ptrace(PTRACE_INTERRUPT, child , 0, 0);
			wait_for_syscall();
		}
	}
	return (0);
}

void	get_sys_ret()
{
	long rax;

	wait_for_syscall();
	rax = ptrace(PTRACE_PEEKUSER, child, RAX * 8, NULL);
	if (rax == -1)
		printf(") = ?\n");
	else if (rax < -1)
		printf(") = -1 %s\n", get_errno_name(rax));
	else
		printf(") = %ld\n", rax);
}

void get_regs()
{
	long regs[6] = {0};

	regs[0] = ptrace(PTRACE_PEEKUSER, child, RDI * 8, NULL);
	regs[1] = ptrace(PTRACE_PEEKUSER, child, RSI * 8, NULL);
	regs[2] = ptrace(PTRACE_PEEKUSER, child, RDX * 8, NULL);
	regs[3] = ptrace(PTRACE_PEEKUSER, child, R10 * 8, NULL);
	regs[4] = ptrace(PTRACE_PEEKUSER, child, ORIG_RAX * 8, NULL);
	if (regs[4] == SYS_clone)
		return ;
	printf("%s(", get_syscall_name(regs[4]));
	if (regs[4] == SYS_exit_group)
	{
		(regs[0]) ? (get_data(regs[0], 0)) : printf("0");
		printf(") = ?\n");
	}
	else
	{
		(regs[0]) ? (get_data(regs[0], 0)) : printf("0");
		(regs[1]) ? (get_data(regs[1], 1)) : 0;
		(regs[2]) ? (get_data(regs[2], 1)) : 0;
		(regs[3]) ? (get_data(regs[3], 1)) : 0;
		get_sys_ret();
	}
}

void		process()
{
	while (42)
	{
		wait_for_syscall();
		if (sigs())
			break ;
		get_regs();
	}
}

char	*check_file(char **argv, char **env)
{
	char **temp;
	char **temp2;

	if (argv[1][0] && argv[1][1] && argv[1][0] == '.' && argv[1][1] == '/')
	{
		if (access(argv[1], F_OK) == -1)
		{
			printf("stat : %s\n", strerror(errno));
			exit(-1);
		}
	}else
	{
		int i = -1;
		while (env[++i])
		{
			temp = ft_strsplit(env[i], '=');
			if (ft_strequ(temp[0], "PATH") == 1)
			{
				int y = -1;
				temp2 = ft_strsplit(temp[1], ':');
				while (temp2[++y])
				{
					temp2[y] = ft_strjoin(temp2[y], "/");
					temp2[y] = ft_strjoin(temp2[y], argv[1]);
					if (access(temp2[y], F_OK) == 0)
					{
						return (temp2[y]);
					}
				}
			}
		}
	}
	return (argv[1]);
}

int	main(int argc, char **argv, char **env)
{
	char *args[2] =  {NULL};
	char *file;

	if (argc < 2)
		print_usage();
	file = check_file(argv, env);
	args[0] = argv[1];
	args[1] = NULL;
	child = fork();
	if (child == 0)
		execve(file, args, env);
	else 
	{
		ptrace(PTRACE_SEIZE, child, 0, 0);
		ptrace(PTRACE_SYSCALL, child, 0, 0);
		ptrace(PTRACE_INTERRUPT, child, 0, 0);
		process();
		get_ret();
	}
	return (0);
}
