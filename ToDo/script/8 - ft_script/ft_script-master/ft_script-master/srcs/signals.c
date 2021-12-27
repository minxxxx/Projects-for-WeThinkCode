/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:45:14 by jcamhi            #+#    #+#             */
/*   Updated: 2018/07/04 16:45:15 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_script.h>

void	handler(int a)
{
	static int	to_kill = 0;

	if (to_kill == 0)
	{
		to_kill = a;
		return ;
	}
	kill(to_kill, SIGKILL);
	if (output_file_singelton(-1) != -1)
	{
		write(1, "\n", 1);
		write_started_message("done", NULL);
		write(output_file_singelton(0), "\n", 1);
		write_time(output_file_singelton(0), "done");
	}
	reset_terminal();
	_exit(87);
}

void	ignore_signals(void)
{
	int					i;
	struct sigaction	new;

	i = 1;
	new.sa_handler = SIG_IGN;
	while (i <= 31)
	{
		if (i == SIGCHLD)
		{
			new.sa_handler = handler;
			sigaction(i, &new, NULL);
			new.sa_handler = SIG_IGN;
		}
		else
			sigaction(i, &new, NULL);
		i++;
	}
}
