/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logical_opperators_part_two.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhuma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:44:38 by amkhuma           #+#    #+#             */
/*   Updated: 2017/11/24 03:44:44 by amkhuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

/*
 ** executes the and opperator in shell
*/

int			ft_and(char *str, t_all *a)
{
	char	**holder;
	int		i;
	int		n;
	int		ret;

	i = -1;
	n = 0;
	ret = 0;
	a->piped = 1;
	while (str[++i])
		n = (str[i] == '&') ? n++ : n;
	if (ft_is_even(n) == 1)
	{
		holder = NULL;
		holder = ft_strsplit(str, '&');
		holder = ft_arrtrim(holder);
		ret = ft_logical_and(holder, a);
		ft_delarray(holder);
	}
	return (ret);
}

/*
 ** Executetes the logical and opperators
*/

void		ft_execvp_edited(char *cmd, t_all *a)
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

/*
** Executes the logical and opperator recursiving by executing a child within
** a child processor.
** see above.
*/

int			ft_logical_and(char **cmds, t_all *a)
{
	int		i;
	int		exitstatus;
	pid_t	father;

	i = -1;
	exitstatus = 0;
	if ((father = fork()) == -1)
		ft_putendl(RED"Forking error: ft_logical_opperators: line 104"RESET);
	else if (father == 0)
	{
		while (cmds[++i] != NULL)
			ft_execvp_edited(cmds[i], a);
		exit(-1);
	}
	else
	{
		wait(&father);
		if (WIFEXITED(father))
		{
			exitstatus = WEXITSTATUS(father);
			if (exitstatus == 0)
				return (2);
		}
	}
	return (0);
}
