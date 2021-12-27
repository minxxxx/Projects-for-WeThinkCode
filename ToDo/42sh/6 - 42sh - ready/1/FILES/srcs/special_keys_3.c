/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_keys_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <dtedgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 10:09:35 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/22 11:06:40 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh.h"

void		go_up(void)
{
	int		diff;

	diff = g_main_line.curs_x - g_main_line.win_col;
	if (diff < 0)
		return ;
	if (g_main_line.curs_x_win)
	{
		ft_puts("up");
		g_main_line.curs_x -= g_main_line.win_col;
		g_main_line.curs_x_win = (g_main_line.curs_x + g_main_line.prompt)
			% g_main_line.win_col;
		g_main_line.curs_y--;
	}
}

void		go_down(void)
{
	int		diff;

	diff = g_main_line.curs_x + g_main_line.win_col;
	if (diff > g_main_line.size_x)
		return ;
	if (g_main_line.curs_x_win)
	{
		f_do(1);
		g_main_line.curs_x += g_main_line.win_col;
		g_main_line.curs_x_win = (g_main_line.curs_x + g_main_line.prompt)
			% g_main_line.win_col;
		g_main_line.curs_y++;
	}
}
