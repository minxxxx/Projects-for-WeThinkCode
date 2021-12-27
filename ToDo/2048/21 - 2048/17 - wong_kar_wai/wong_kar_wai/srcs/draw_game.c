/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:07:23 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/01 17:32:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include <ncurses.h>

static void		cell_color(int nb)
{
	int				i;

	if (nb == 0)
	{
		attron(COLOR_PAIR(1));
		return ;
	}
	i = 1;
	while (++i < 13)
		if ((nb /= 2) == 1)
		{
			attron(COLOR_PAIR(i));
			return ;
		}
	attron(COLOR_PAIR(13));
}

static void		draw_rect(t_rect rect)
{
	attron(COLOR_PAIR(20));
	rect.height += rect.y;
	WPUT(rect.x, rect.y, "% *c", rect.width, ' ');
	while (rect.y < rect.height)
	{
		WPUT(rect.x, rect.y, " ");
		WPUT(rect.x + rect.width - 1, rect.y, " ");
		rect.y++;
	}
	WPUT(rect.x, rect.y, "% *c", rect.width, ' ');
}

static void		draw_cell(t_rect cell, int nb)
{
	const t_rect	tmp = cell;
	char			str[12];
	int				len;
	int				middle;

	cell_color(nb);
	middle = cell.height / 2 + cell.y;
	cell.height += cell.y;
	while ((cell.y + 1) < cell.height)
	{
		if (cell.y != middle)
			WPUT(cell.x, cell.y, "% *c", cell.width, ' ');
		cell.y++;
	}
	WPUT(cell.x, cell.y, "% *c", cell.width, ' ');
	len = (cell.width - ft_itoab(nb, str)) / 2;
	WPUT(cell.x, middle, "% *c%s% *c", len, ' ', str, len, ' ');
	draw_rect(tmp);
}

static void		draw_score(t_env *env)
{
	attron(COLOR_PAIR(20));
	wmove(stdscr, 0, 0);
	if (env->score <= env->best_score)
		printw("% *c", env->win_width - printw("Score: %d ; Best: %d",
			env->score, env->best_score), ' ');
	else
		printw("% *c", env->win_width - printw("Score: %d ; Best: %d",
			env->score, env->score), ' ');
}

void			draw_game(t_env *env)
{
	t_rect			cell;
	t_pt			i;

	cell = RECT(0, 0, 0, 0);
	cell.width = ft_max(env->win_width / env->map_size, 5);
	cell.height = ft_max(env->win_height / env->map_size, 3);
	clear();
	draw_score(env);
	i.y = -1;
	while (++i.y < env->map_size)
	{
		cell.y = i.y * cell.height + 1;
		i.x = -1;
		while (++i.x < env->map_size)
		{
			cell.x = i.x * cell.width;
			draw_cell(cell, MAP_GET(env, i.x, i.y));
		}
	}
	refresh();
	attron(COLOR_PAIR(50));
}
