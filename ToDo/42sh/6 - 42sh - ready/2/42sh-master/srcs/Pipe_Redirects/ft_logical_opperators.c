/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logical_opperators.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhuma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 11:09:02 by amkhuma           #+#    #+#             */
/*   Updated: 2017/11/24 03:44:54 by amkhuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

void		and(char *str, t_all *a)
{
	if (ft_strstr(str, " && ") == NULL)
	{
		ft_execvp(str, a);
		ft_cmd_unknown(str);
		exit(10);
	}
	else
	{
		ft_and_2(str, a);
		exit(20);
	}
	ft_putendl("exiting");
}

int			ft_exit_checks(int ext, int *i, char **cmds)
{
	if (ext == 10)
		*i += 1;
	else if (ext == 20)
		*i += 1;
	else if (ext == 1 && ft_strstr(cmds[*i], " && ") != NULL)
		return (0);
	else if (ext == 1 && ft_strstr(cmds[*i], " && ") == NULL)
		*i += 1;
	else if (ext == 0)
		return (0);
	return (1);
}

/*
** Logical or opperator and checks if it has "&&" in it. if it does it will
** split it up and run it recursively until it fails, ends or executes the
** first OR properly.
*/

void		ft_logical_or(char **cmds, t_all *a)
{
	int		i;
	int		ext;
	pid_t	father;

	i = 0;
	while (cmds[i])
	{
		if ((father = fork()) == -1)
			ft_putendl("Forking error: ft_logical_opperators: line 22");
		else if (father == 0)
			and(cmds[i], a);
		else
		{
			wait(&father);
			if (WIFEXITED(father))
			{
				ext = (WEXITSTATUS(father));
				if (ft_exit_checks(ext, &i, cmds) == 0)
					break ;
			}
		}
	}
}
