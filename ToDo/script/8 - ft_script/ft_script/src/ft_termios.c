/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termios.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dw31 <dw31@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 20:44:05 by dw31              #+#    #+#             */
/*   Updated: 2015/11/08 17:02:09 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_script.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

int				ft_tcattr(int fd, struct termios *t, t_bool isget)
{
	if (isget)
		return (ioctl(fd, TIOCGETA, t));
	return (ioctl(fd, TIOCSETAW, t));
}

void			ft_cfmakeraw(struct termios *t)
{
	t->c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL
		| IXON);
	t->c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
	t->c_cflag &= ~(CSIZE | PARENB);
	t->c_cflag |= CS8;
	t->c_cc[VMIN] = 1;
	t->c_cc[VTIME] = 0;
}

static int		open_pty_tty(char c, char b16, t_bool ispty)
{
	char	testname[11];

	ft_bzero(&testname[0], 11);
	if (ispty)
		ft_memcpy(testname, "/dev/pty", 8);
	else
		ft_memcpy(testname, "/dev/tty", 8);
	testname[8] = c;
	testname[9] = b16;
	if (ispty)
		return (open(&testname[0], O_RDWR));
	return (open(&testname[0], O_RDWR | O_NOCTTY));
}

t_bool			ft_openpt(t_env *env)
{
	const char		*b16 = "0123456789abcdef";
	struct winsize	win;
	char			c;
	int				n;

	ioctl(0, TIOCGWINSZ, &win);
	c = 'o';
	while (++c <= 'w')
	{
		n = -1;
		while (b16[++n])
		{
			if ((PTM = open_pty_tty(c, b16[n], TRUE)) != -1)
			{
				if ((PTS = open_pty_tty(c, b16[n], FALSE)) != -1)
				{
					ioctl(PTM, TIOCSWINSZ, &win);
					return (TRUE);
				}
				close(PTM);
			}
		}
	}
	return (FALSE);
}
