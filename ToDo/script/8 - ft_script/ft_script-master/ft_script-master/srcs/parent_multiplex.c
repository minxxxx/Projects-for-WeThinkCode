/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_multiplex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:42:29 by jcamhi            #+#    #+#             */
/*   Updated: 2018/07/04 16:42:29 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_script.h>

void	command_user_multiplex(int mfd, int fd, struct termios *old)
{
	char	obuffer[2048];
	int		r;

	while (1)
	{
		r = read(mfd, obuffer, 2048);
		if (r == -1)
		{
			ioctl(0, TIOCSETA, old);
			_exit(4);
		}
		write(fd, obuffer, r);
		write(1, obuffer, r);
	}
}

void	user_command_multiplex(int mfd, int fd, struct termios *old, t_opt *opt)
{
	char	ibuffer[2048];
	int		r;

	while (1)
	{
		r = read(0, ibuffer, 2048);
		if (r == -1)
		{
			ioctl(0, TIOCSETA, old);
			_exit(5);
		}
		if (opt->options & K_OPT)
		{
			if (r > 0 && ibuffer[r - 1] == '\n')
			{
				write(fd, ibuffer, r - 1);
				write(fd, "\r", 1);
			}
			else
				write(fd, ibuffer, r);
		}
		write(mfd, ibuffer, r);
	}
}
