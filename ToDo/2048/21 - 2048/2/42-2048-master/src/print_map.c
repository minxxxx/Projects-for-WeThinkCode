/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 14:01:21 by jfrancho          #+#    #+#             */
/*   Updated: 2016/02/02 13:33:20 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_2048.h"

static void		set_color3(t_map *map, int j, int i)
{
	if (map->tab[j][i] == 256)
	{
		init_pair(9, COLOR_YELLOW, COLOR_WHITE);
		attron(COLOR_PAIR(9));
	}
	if (map->tab[j][i] == 512)
	{
		init_pair(10, COLOR_RED, COLOR_WHITE);
		attron(COLOR_PAIR(10));
	}
	else if (map->tab[j][i] == 1024)
	{
		init_pair(11, COLOR_BLACK, COLOR_WHITE);
		attron(COLOR_PAIR(11));
	}
	else if (map->tab[j][i] == 2048)
	{
		init_pair(12, COLOR_MAGENTA, COLOR_WHITE);
		attron(COLOR_PAIR(12));
	}
}

static void		set_color2(t_map *map, int j, int i)
{
	if (map->tab[j][i] == 16)
	{
		init_pair(5, COLOR_WHITE, COLOR_CYAN);
		attron(COLOR_PAIR(5));
	}
	if (map->tab[j][i] == 32)
	{
		init_pair(6, COLOR_WHITE, COLOR_MAGENTA);
		attron(COLOR_PAIR(6));
	}
	else if (map->tab[j][i] == 64)
	{
		init_pair(7, COLOR_GREEN, COLOR_WHITE);
		attron(COLOR_PAIR(7));
	}
	else if (map->tab[j][i] == 128)
	{
		init_pair(8, COLOR_BLUE, COLOR_WHITE);
		attron(COLOR_PAIR(8));
	}
	else
		set_color3(map, j, i);
}

static void		set_color(t_map *map, int j, int i)
{
	if (map->tab[j][i] == 0)
	{
		init_pair(1, COLOR_WHITE, COLOR_BLACK);
		attron(COLOR_PAIR(1));
	}
	if (map->tab[j][i] == 2)
	{
		init_pair(2, COLOR_WHITE, COLOR_RED);
		attron(COLOR_PAIR(2));
	}
	else if (map->tab[j][i] == 4)
	{
		init_pair(3, COLOR_WHITE, COLOR_GREEN);
		attron(COLOR_PAIR(3));
	}
	else if (map->tab[j][i] == 8)
	{
		init_pair(4, COLOR_WHITE, COLOR_YELLOW);
		attron(COLOR_PAIR(4));
	}
	else
		set_color2(map, j, i);
}

static void		print_block(int y, int x)
{
	int ymin;
	int xmin;

	ymin = ((LINES / 4) * y) - 1;
	while (++ymin < ((LINES / 4) * (y + 1)))
	{
		xmin = ((COLS / 4) * x) - 1;
		while (++xmin < ((COLS / 4) * (x + 1)))
			mvprintw(ymin, xmin, "%s", " ");
	}
}

void			print_map(t_map *map)
{
	int			i;
	int			j;

	raw();
	keypad(stdscr, TRUE);
	noecho();
	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
		{
			set_color(map, j, i);
			print_block(j, i);
			if (map->tab[j][i] != 0)
				mvprintw((j * LINES / 4) + LINES / 8, (i * COLS / 4) + COLS / 8,\
				"%d", map->tab[j][i]);
		}
	}
}
