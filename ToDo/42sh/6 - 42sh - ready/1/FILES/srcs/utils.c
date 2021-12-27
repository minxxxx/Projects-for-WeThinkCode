/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 16:20:16 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/26 16:20:19 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh.h"

static int		myoutc(int c)
{
	return (write(1, &c, 1));
}

void			ft_puts(char *res)
{
	tputs(tgetstr(res, NULL), 1, myoutc);
}

void			fmove(int x, int y)
{
	tputs(tgoto(tgetstr("cm", NULL), x, y), 1, myoutc);
}

void			fmovex(int x)
{
	tputs(tgoto(tgetstr("ch", NULL), 0, x), 1, myoutc);
}

void			f_do(int x)
{
	tputs(tgoto(tgetstr("DO", NULL), 0, x), 1, myoutc);
}
