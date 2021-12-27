/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_reverse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhuma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:06:51 by amkhuma           #+#    #+#             */
/*   Updated: 2017/11/24 03:46:21 by amkhuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

/*
 ** This function is for the "<" opperator.
*/

void		ft_reverse_direct(char **holder, t_all *a)
{
	t_reverse_direct	b;
	pid_t				father;

	b.i = 1;
	if (holder[b.i] != NULL)
	{
		while (holder[b.i] != NULL)
		{
			b.cmds = ft_strsplit(holder[0], ' ');
			father = fork();
			if (father > 0)
				wait(0);
			if (father == 0)
			{
				close(0);
				b.fd = open(holder[b.i], O_RDONLY);
				ft_execvp(holder[0], a);
				ft_cmd_unknown(b.cmds[0]);
				exit(0);
			}
			ft_delarray(b.cmds);
			b.i++;
		}
	}
}
