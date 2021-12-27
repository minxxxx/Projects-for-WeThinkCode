/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:33:28 by khansman          #+#    #+#             */
/*   Updated: 2016/11/27 12:33:29 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

int		cursor_do(int to_print)
{
	write(1, &to_print, 1);
	return (to_print);
}

void	unexpected_error(int signo)
{
	if (signo == 11)
	{
		tputs(tgetstr((char *)"up", NULL), 0, cursor_do);
		tputs(tgetstr((char *)"cr", NULL), 0, cursor_do);
		ft_putstr("                                                         ");
		tputs(tgetstr((char *)"cr", NULL), 0, cursor_do);
		error_quit("\r\rError: an unlabled error occured.");
	}
}

void	listener(void)
{
	signal(11, unexpected_error);
}
