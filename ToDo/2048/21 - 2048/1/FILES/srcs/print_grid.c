/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:15:24 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/31 15:41:40 by sboulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

static void		reset_screen(void)
{
	initscr();
	clear();
	noecho();
	raw();
	curs_set(0);
	keypad(stdscr, TRUE);
	start_color();
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(8, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(16, COLOR_BLACK, COLOR_YELLOW);
	init_pair(32, COLOR_BLACK, COLOR_RED);
	init_pair(64, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(128, COLOR_RED, COLOR_YELLOW);
	init_pair(256, COLOR_RED, COLOR_BLACK);
	init_pair(512, COLOR_RED, COLOR_BLACK);
	init_pair(1024, COLOR_RED, COLOR_BLACK);
	init_pair(2048, COLOR_RED, COLOR_BLACK);
	refresh();
}

static void		get_window_size(t_game_infos *game_infos)
{
	int		square_size;

	if (LINES < (game_infos->size * 6) || COLS < (game_infos->size * 12))
	{
		free_struct(game_infos);
		ft_putendl("Window too small. GAME OVER !");
		exit(0);
	}
	square_size = (COLS / 2) < LINES ? COLS - 5 : LINES * 2 - 10;
	game_infos->width = square_size / game_infos->size;
	game_infos->height = (square_size / game_infos->size) / 2;
}

void			print_grid(t_game_infos *game_infos)
{
	int		row;
	int		col;
	WINDOW	*cur_win;
	int		i;

	i = 0;
	reset_screen();
	get_window_size(game_infos);
	row = -1;
	while (++row < game_infos->size && (col = -1))
	{
		while (++col < game_infos->size)
		{
			cur_win = create_newwin(game_infos->height, game_infos->width,
					row * game_infos->height, col * game_infos->width);
			game_infos->windows[i++] = cur_win;
			wbkgd(cur_win, COLOR_PAIR(game_infos->grid[row][col]));
			if (game_infos->grid[row][col] != 0)
				mvwprintw(cur_win, game_infos->height / 2,
					game_infos->width / 2, "%d", (game_infos->grid)[row][col]);
			wrefresh(cur_win);
		}
	}
	print_game_stats(game_infos);
}
