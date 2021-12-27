/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <dtedgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 10:09:21 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/26 15:48:30 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh.h"

void		go_to_start(void)
{
	int i;

	i = g_main_line.curs_y;
	g_main_line.curs_x = 0;
	g_main_line.curs_y = 0;
	g_main_line.curs_x_win = g_main_line.prompt;
	while (i > 0)
	{
		ft_puts("up");
		i--;
	}
	fmovex(g_main_line.curs_x_win);
}

void		go_to_end(void)
{
	print_line(0);
	g_main_line.curs_x = g_main_line.size_x;
	g_main_line.curs_x_win = (g_main_line.size_x + 3) % g_main_line.win_col;
	g_main_line.curs_y = (g_main_line.size_x + 3) / g_main_line.win_col;
}

void		cut_entire_line(void)
{
	free(g_main_line.clipboard);
	g_main_line.clipboard = ft_strdup(g_main_line.cmd);
	go_to_start();
	ft_puts("cd");
	init_new_line();
}

void		cut_end_of_line(void)
{
	int		i;

	free(g_main_line.clipboard);
	g_main_line.clipboard = ft_strsub(g_main_line.cmd, g_main_line.curs_x,
			g_main_line.size_x - g_main_line.curs_x);
	g_main_line.size_x -= ft_strlen(g_main_line.clipboard);
	g_main_line.cmd = ft_strsub(g_main_line.cmd, 0, g_main_line.size_x);
	i = g_main_line.curs_y;
	ft_puts("sc");
	while (i < g_main_line.size_y)
	{
		ft_puts("ce");
		ft_puts("do");
		ft_puts("le");
		i++;
	}
	ft_puts("rc");
}

void		paste(void)
{
	g_main_line.cmd = ft_str_insert(g_main_line.cmd, g_main_line.clipboard,
			g_main_line.curs_x);
	print_line(0);
	g_main_line.size_x += ft_strlen(g_main_line.clipboard);
	g_main_line.curs_x = g_main_line.size_x;
	g_main_line.curs_x_win = (g_main_line.size_x + g_main_line.prompt)
		% g_main_line.win_col;
	g_main_line.curs_y = (g_main_line.size_x + g_main_line.prompt)
		/ g_main_line.win_col;
}
