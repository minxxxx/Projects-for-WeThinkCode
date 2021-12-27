/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 14:16:01 by fkoehler          #+#    #+#             */
/*   Updated: 2016/08/29 15:43:59 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	echo_param(char *param, char *next_param)
{
	ft_putstr(param);
	if (next_param)
		ft_putchar(' ');
}

int			ft_echo(char **cmd)
{
	int		i;
	int		flag_n;
	t_shell	*shell;

	flag_n = 0;
	shell = get_struct(0);
	if (cmd[1] && (ft_strcmp(cmd[1], "-n") == 0))
		flag_n = 1;
	i = flag_n;
	if ((cmd[1] && cmd[1][0]) || (cmd[1] && cmd[2]))
	{
		while (cmd[++i])
			echo_param(cmd[i], cmd[i + 1]);
	}
	if (!flag_n)
		ft_putchar('\n');
	else if (cmd[2] && (cmd[2][0] || cmd[3]))
	{
		tputs(tgetstr("mr", NULL), shell->fd[3], &putchar);
		ft_putchar('%');
		tputs(tgetstr("me", NULL), shell->fd[3], &putchar);
		tputs(tgetstr("do", NULL), shell->fd[3], &putchar);
	}
	return (0);
}
