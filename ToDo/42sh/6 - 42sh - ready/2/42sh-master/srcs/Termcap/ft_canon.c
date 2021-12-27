/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canon.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 04:16:53 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 03:47:15 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

static int	ft_ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int			non_canonical(struct termios *term, char *status)
{
	if (!ft_strcmp(status, "start"))
	{
		tcgetattr(STDIN_FILENO, term);
		term->c_cc[VMIN] = 1;
		term->c_cc[VTIME] = 0;
		term->c_lflag &= ~(ICANON | ECHO);
		tcsetattr(STDOUT_FILENO, TCSANOW, term);
	}
	else if (!ft_strcmp(status, "end"))
	{
		term->c_lflag |= (ICANON | ECHO);
		tputs(tgetstr("te", 0), 1, ft_ft_putchar);
		tputs(tgetstr("ve", 0), 1, ft_ft_putchar);
		tputs(tgetstr("me", NULL), 1, ft_ft_putchar);
		tcsetattr(0, 0, term);
	}
	return (1);
}
