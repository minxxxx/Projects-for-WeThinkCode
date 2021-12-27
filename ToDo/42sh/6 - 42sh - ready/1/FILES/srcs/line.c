/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <dtedgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 10:08:32 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/22 11:53:28 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh.h"

void		free_line(t_line *line)
{
	ft_strdel(&line->cmd);
	ft_memdel((void **)line);
}

int			chars_by_line(int line_nb)
{
	int		total_size;
	int		res;

	if (line_nb < 1 || line_nb > g_main_line.size_y)
		return (0);
	total_size = ft_strlen(g_main_line.cmd) + g_main_line.prompt;
	res = total_size - (line_nb - 1) * g_main_line.win_col;
	if (line_nb == 1)
		return (res - g_main_line.prompt);
	else
		return (res);
}

void		init_new_line(void)
{
	free(g_main_line.cmd);
	g_main_line.cmd = ft_strnew(1);
	g_main_line.curs_x = 0;
	g_main_line.curs_x_win = g_main_line.prompt;
	g_main_line.curs_y = 0;
	g_main_line.size_x = 0;
	g_main_line.size_y = 1;
	get_window_size();
}

void		init_line(int size_prompt)
{
	if (g_main_line.cmd)
		free(g_main_line.cmd);
	g_main_line.cmd = NULL;
	g_main_line.cmd = ft_strnew(1);
	g_main_line.clipboard = ft_strnew(1);
	g_main_line.prompt = ft_strlen(PROMPT);
	get_window_size();
	if (g_main_line.win_col != 0)
		g_main_line.size_prompt = (size_prompt / g_main_line.win_col) + 1;
	g_main_line.curs_x = 0;
	g_main_line.curs_x_win = g_main_line.prompt;
	g_main_line.curs_y = 0;
	g_main_line.size_x = 0;
	g_main_line.size_y = 1;
}
