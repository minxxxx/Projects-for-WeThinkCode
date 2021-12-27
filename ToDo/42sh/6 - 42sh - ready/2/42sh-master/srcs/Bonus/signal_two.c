/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 11:37:44 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:48:22 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

int		ft_save(int i)
{
	static int	n = 0;
	int			tmp;

	if (i == 0)
	{
		tmp = n;
		n = 0;
		return (tmp);
	}
	else
	{
		n = 0;
		n = n + i;
		return (0);
	}
}

void	signal_sigint(int sig)
{
	if (sig == SIGINT)
	{
		ft_save(sig);
		ft_putstr("\n");
		ft_print_dir();
		signal(SIGTSTP, signal_sigkill);
	}
}

/*
 ** Handles signals when forking.
*/

void	fork_signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		ft_putendl("\n");
		signal(SIGINT, fork_signal_handler);
	}
}

/*
 ** Handles different signals in one go
*/

void	handle_signals(t_all *a)
{
	(void)a->yes;
	signal(SIGINT, signal_sigint);
	signal(SIGTSTP, signal_sigkill);
}
