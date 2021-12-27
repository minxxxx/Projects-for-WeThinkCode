/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_keys_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <dtedgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 10:09:27 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/22 20:14:14 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh.h"

void			move_front(void)
{
	if (g_main_line.curs_x_win == g_main_line.win_col - 1)
	{
		g_main_line.curs_y++;
		g_main_line.curs_x_win = 0;
		go_start_next_line();
	}
	else
	{
		g_main_line.curs_x_win++;
		ft_puts("nd");
	}
	g_main_line.curs_x++;
}

void			move_back(void)
{
	if (g_main_line.curs_x_win == 0)
	{
		g_main_line.curs_y--;
		g_main_line.curs_x_win = g_main_line.win_col - 1;
		go_end_line_before();
	}
	else
	{
		g_main_line.curs_x_win--;
		ft_puts("le");
	}
	g_main_line.curs_x--;
}

void			move_back_word(void)
{
	char		*tmp;
	int			i;

	tmp = g_main_line.cmd;
	i = g_main_line.curs_x;
	if (i > 0 && (tmp[i] != ' ' || tmp[i] != '\t'))
	{
		move_back();
		i--;
	}
	while (i >= 0 && (tmp[i] == ' ' || tmp[i] == '\t'))
	{
		move_back();
		i--;
	}
	while (i > 0 && tmp[i - 1] != ' ' && tmp[i - 1] != '\t')
	{
		move_back();
		i--;
	}
}

void			move_next_word(void)
{
	char		*tmp;
	int			i;
	int			max;

	tmp = g_main_line.cmd;
	i = g_main_line.curs_x;
	max = g_main_line.size_x;
	while (i < max && tmp[i] != ' ' && tmp[i] != '\t')
	{
		move_front();
		i++;
	}
	while (i < max && (tmp[i] == ' ' || tmp[i] == '\t'))
	{
		move_front();
		i++;
	}
}
