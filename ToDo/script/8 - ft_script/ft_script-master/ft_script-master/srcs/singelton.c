/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singelton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:45:54 by jcamhi            #+#    #+#             */
/*   Updated: 2018/07/04 16:45:54 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_script.h>

struct termios	*singelton_tty(struct termios *old)
{
	static char				i = 0;
	static struct termios	save;

	if (i == 0)
	{
		ft_memcpy(&save, old, sizeof(save));
		i = 1;
	}
	return (&save);
}

void			reset_terminal(void)
{
	ioctl(0, TIOCSETA, singelton_tty(NULL));
}

int				output_file_singelton(int param)
{
	static int	fd = -1;

	if (fd == -1)
		fd = param;
	return (fd);
}
