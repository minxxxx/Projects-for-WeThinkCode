/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 12:50:36 by sfranc            #+#    #+#             */
/*   Updated: 2017/10/03 11:19:37 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

void	ft_exit_shell(char *str, int ret)
{
	int i;

	if (str)
		ft_putendl_fd(str, 2);
	g_shell->env ? ft_freetab(&g_shell->env) : 0;
	g_shell->history ? ft_freetab(&g_shell->history) : 0;
	free(g_shell);
	i = 0;
	while (i < 32)
		signal(i++, SIG_DFL);
	exit(ret);
}
