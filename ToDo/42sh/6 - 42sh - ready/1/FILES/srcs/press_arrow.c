/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_arrow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <dtedgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 10:08:46 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/22 11:53:30 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh.h"

static void		arrow_up(t_hist *history, t_hist **tmp)
{
	int			i;

	i = g_main_line.size_y;
	while (i-- > 1)
		ft_puts("up");
	ft_puts("cr");
	ft_puts("cd");
	free(g_main_line.cmd);
	g_main_line.cmd = ft_strdup((*tmp)->cmd);
	g_main_line.curs_x = (*tmp)->size;
	g_main_line.size_x = g_main_line.curs_x;
	g_main_line.curs_x_win = (g_main_line.size_x + g_main_line.prompt)
		% g_main_line.win_col;
	g_main_line.curs_y = (g_main_line.size_x + g_main_line.prompt)
		/ g_main_line.win_col;
	g_main_line.size_y = g_main_line.curs_y + 1;
	prompt(NULL, g_main_line.cmd);
	if ((*tmp) == history)
		return ;
	(*tmp) = (*tmp)->next;
	return ;
}

static void		arrow_down(t_hist *history, t_hist **tmp)
{
	int			i;

	i = g_main_line.size_y;
	while (i-- > 1)
		ft_puts("up");
	ft_puts("cr");
	ft_puts("cd");
	free(g_main_line.cmd);
	g_main_line.cmd = ft_strdup((*tmp)->cmd);
	g_main_line.curs_x = (*tmp)->size;
	g_main_line.curs_x_win = (g_main_line.size_x + g_main_line.prompt)
		% g_main_line.win_col;
	g_main_line.size_x = g_main_line.curs_x;
	g_main_line.curs_y = (g_main_line.size_x + g_main_line.prompt)
		/ g_main_line.win_col;
	g_main_line.size_y = g_main_line.curs_y + 1;
	prompt(NULL, g_main_line.cmd);
	if ((*tmp) == history->next)
		return ;
	(*tmp) = (*tmp)->prev;
	return ;
}

static void		left_arrow(void)
{
	if (g_main_line.size_x > 0 && g_main_line.curs_x > 0)
	{
		g_main_line.curs_x--;
		if (g_main_line.curs_x_win == 0)
		{
			g_main_line.curs_y--;
			g_main_line.curs_x_win = g_main_line.win_col - 1;
			ft_puts("up");
			fmovex(g_main_line.win_col - 1);
		}
		else
		{
			g_main_line.curs_x_win--;
			ft_puts("le");
		}
	}
}

static void		right_arrow(void)
{
	if (g_main_line.curs_x < g_main_line.size_x)
	{
		g_main_line.curs_x++;
		if (g_main_line.curs_x_win == g_main_line.win_col - 1)
		{
			g_main_line.curs_x_win = 0;
			g_main_line.curs_y++;
			ft_puts("do");
			ft_puts("cr");
		}
		else
		{
			g_main_line.curs_x_win++;
			ft_puts("nd");
		}
	}
}

int				press_arrow(char key, t_hist *history, t_hist **tmp, int i)
{
	if (key == 66 && history && i == 1)
		arrow_down(history, tmp);
	else if (key == 65 && history)
	{
		i = 1;
		arrow_up(history, tmp);
	}
	else if (key == 68)
		left_arrow();
	else if (key == 67)
		right_arrow();
	return (i);
}
