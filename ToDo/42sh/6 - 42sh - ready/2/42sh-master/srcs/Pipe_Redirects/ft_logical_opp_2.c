/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logical_opperators.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhuma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 11:09:02 by amkhuma           #+#    #+#             */
/*   Updated: 2017/11/24 03:44:44 by amkhuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"
#define STATUS  if(exitstatus==0)exit(1)

void		ft_execvp_edited_2(char *cmd, t_all *a)
{
	t_execvp	b;

	b.exitstatus = 0;
	if ((b.father = fork()) == -1)
		ft_putendl("FORK error");
	else if (b.father == 0)
	{
		b.cmds = ft_strsplit(cmd, ' ');
		execve(b.cmds[0], b.cmds, a->new);
		b.cmds[0] = ft_add_path(b.cmds[0], a);
		execve(b.cmds[0], b.cmds, a->new);
		ft_cmd_unknown(cmd);
		ft_delarray(b.cmds);
		exit(-1);
	}
	else
	{
		wait(&b.father);
		if (WIFEXITED(b.father))
		{
			b.exitstatus = WEXITSTATUS(b.father);
			if (b.exitstatus != 0)
				exit(-1);
		}
	}
}

void		ft_logical_and_2(char **cmds, t_all *a)
{
	int		i;
	int		exitstatus;
	int		total;
	pid_t	father;

	i = -1;
	total = (ft_arraylen(cmds) + 1);
	exitstatus = 0;
	if ((father = fork()) == -1)
		ft_putendl("Forking error: ft_logical_opperators: line 22");
	else if (father == 0)
	{
		while (cmds[++i] != NULL && --total)
			ft_execvp_edited_2(cmds[i], a);
		(total == 0) ? exit(total) : exit(1);
	}
	else
	{
		wait(&father);
		if (WIFEXITED(father))
		{
			exitstatus = (WEXITSTATUS(father) / 255);
			STATUS;
		}
	}
}

void		ft_and_2(char *str, t_all *a)
{
	char	**holder;
	int		i;
	int		n;

	i = -1;
	n = 0;
	a->piped = 1;
	while (str[++i])
		n = (str[i] == '&') ? n++ : n;
	if (ft_is_even(n) == 1)
	{
		holder = NULL;
		holder = ft_strsplit(str, '&');
		holder = ft_arrtrim(holder);
		ft_logical_and_2(holder, a);
		ft_delarray(holder);
	}
}
