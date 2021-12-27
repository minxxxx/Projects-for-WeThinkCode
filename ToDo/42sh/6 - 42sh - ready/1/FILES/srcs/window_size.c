/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 16:20:07 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/26 16:20:08 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh.h"

void		clear(void)
{
	ft_puts("ho");
	ft_puts("cd");
	prompt(NULL, g_main_line.cmd);
	g_main_line.curs_x = g_main_line.size_x;
	g_main_line.curs_x_win = (g_main_line.size_x + 3) % (g_main_line.win_col);
	g_main_line.curs_y = (g_main_line.size_x + 3) / (g_main_line.win_col);
	g_main_line.size_y = g_main_line.curs_y + g_main_line.size_prompt;
}

void		get_window_size(void)
{
	struct winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	g_main_line.win_col = win.ws_col;
	g_main_line.win_row = win.ws_row;
}

void		clr_screen(void)
{
	if (g_main_line.size_x >= (0.90 * g_main_line.win_col))
		clear();
}

void		resize(void)
{
	get_window_size();
	clr_screen();
}
