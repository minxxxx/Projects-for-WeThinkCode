/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <dtedgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 10:09:15 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/22 11:53:33 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh.h"

void				handle_ctrl_d(void)
{
	ft_puts("do");
	default_terminal_mode();
	exit(0);
}

void				handle_ctrl_c(void)
{
	go_to_start();
	ft_puts("cd");
	init_new_line();
}

static void			sighandler(int signum)
{
	if (signum == SIGQUIT || signum == SIGKILL)
		return ;
	else if (signum == SIGWINCH)
		resize();
	else if (signum == SIGINT)
		handle_ctrl_d();
	else if (signum == SIGSEGV)
	{
		ft_printf("Action not supported\nExiting program...\n");
		exit(0);
	}
}

void				ft_signal(void)
{
	int				i;

	i = 1;
	while (i < 32)
	{
		signal(i, sighandler);
		i++;
	}
}
