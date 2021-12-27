/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <dtedgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 10:08:26 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/22 11:53:28 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh.h"

int					default_terminal_mode(void)
{
	struct termios	tattr;

	if (tcgetattr(0, &tattr) == -1)
		return (-1);
	tattr.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, 0, &tattr) == -1)
		return (-1);
	return (1);
}

int					raw_terminal_mode(void)
{
	struct termios	tattr;

	if (tgetent(NULL, getenv("TERM")) != 1)
	{
		ft_printf("Cannot find environment TERM\n");
		return (-1);
	}
	if (tcgetattr(0, &tattr) == -1)
		return (-1);
	tattr.c_lflag &= ~(ECHO | ICANON);
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	tattr.c_cc[VEOF] = 3;
	tattr.c_cc[VINTR] = 4;
	if (tcsetattr(0, TCSADRAIN, &tattr) == -1)
		return (-1);
	return (1);
}
