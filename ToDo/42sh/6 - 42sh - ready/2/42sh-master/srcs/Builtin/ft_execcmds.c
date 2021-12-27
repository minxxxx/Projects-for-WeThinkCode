/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execcmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 09:38:38 by mnaidoo           #+#    #+#             */
/*   Updated: 2017/11/24 02:50:34 by mnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

void	ft_execpath(char *path, t_all *a)
{
	pid_t	father;
	int		i;

	i = 0;
	father = fork();
	signal(SIGINT, fork_signal_handler);
	if (father > 0)
		wait(0);
	if (father == 0)
	{
		if (hasglob(a->array) > 0)
			i = implementg(a);
		if (i != -1)
		{
			execve(path, &a->array[0], a->new);
			ft_cmd_unknown(a->array[0]);
		}
		else
			ft_putendl("Error: could not find the file name");
		exit(0);
	}
}

void	ft_execcurr(t_all *a, struct termios *term)
{
	pid_t	father;
	int		i;

	(void)term;
	i = 0;
	father = fork();
	signal(SIGINT, fork_signal_handler);
	if (father > 0)
		wait(0);
	if (father == 0)
	{
		if (hasglob(a->array) > 0)
			i = implementg(a);
		sleep(1);
		if (i != -1)
		{
			execve(a->array[0], &a->array[0], a->new);
			ft_cmd_unknown(a->array[0]);
		}
		else
			ft_putendl("Error: could not find the file name");
		exit(0);
	}
}
