/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 10:17:45 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/31 17:27:06 by sboulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

static void		init_game(t_game_infos *game_infos, int ac, char **av)
{
	int		i;

	if (ac != 2)
		game_infos->size = 4;
	else if (ac == 2)
		game_infos->size = ft_atoi(av[1]) >= 3 && ft_atoi(av[1]) < 9
			? ft_atoi(av[1]) : 4;
	game_infos->grid = (int **)ft_memalloc(sizeof(int *) * game_infos->size);
	i = 0;
	while (i < game_infos->size)
	{
		game_infos->grid[i] = (int *)ft_memalloc(sizeof(int)
				* game_infos->size);
		i++;
	}
	place_number(game_infos);
	place_number(game_infos);
	game_infos->windows = (WINDOW **)ft_memalloc(sizeof(WINDOW *)
			* ((game_infos->size * game_infos->size) + 2));
	game_infos->start_time = time(NULL);
}

static void		check_key(int key, t_game_infos *game_infos)
{
	int	ret;

	if (!wk_test_up(game_infos->grid, game_infos->size)
			&& !wk_test_right(game_infos->grid, game_infos->size)
			&& !wk_test_down(game_infos->grid, game_infos->size)
			&& !wk_test_left(game_infos->grid, game_infos->size))
	{
		free_struct(game_infos);
		ft_putendl("GAME OVER !");
		exit(0);
	}
	if (key == 258 || key == 259 || key == 260 || key == 261)
	{
		ret = key == 260 && wk_test_left(game_infos->grid, game_infos->size)
			? wk_move_left(game_infos->grid, game_infos->size) : 0;
		ret = key == 259 && wk_test_up(game_infos->grid, game_infos->size)
			? wk_move_up(game_infos->grid, game_infos->size) : ret;
		ret = key == 261 && wk_test_right(game_infos->grid, game_infos->size)
			? wk_move_right(game_infos->grid, game_infos->size) : ret;
		ret = key == 258 && wk_test_down(game_infos->grid, game_infos->size)
			? wk_move_down(game_infos->grid, game_infos->size) : ret;
		game_infos->moves += ret > 0 ? place_number(game_infos) : 0;
		is_victory(game_infos, game_infos->grid);
	}
}

static void		start_screen(void)
{
	int		key;

	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	raw();
	mvprintw(LINES / 2, COLS / 2 - 15, "PRESS <ENTER> TO START PLAYING");
	mvprintw((LINES / 2) + 2, COLS / 2 - 10, "PRESS <ESCAPE> TO EXIT");
	while ((key = getch()) != 10)
	{
		clear();
		mvprintw(LINES / 2, COLS / 2 - 15, "PRESS <ENTER> TO START PLAYING");
		mvprintw((LINES / 2) + 2, COLS / 2 - 10, "PRESS <ESCAPE> TO EXIT");
		if (key == 27)
		{
			endwin();
			exit(0);
		}
	}
}

int				main(int ac, char **av)
{
	int				key;
	t_game_infos	*game_infos;

	start_screen();
	game_infos = (t_game_infos *)ft_memalloc(sizeof(t_game_infos));
	init_game(game_infos, ac, av);
	is_victory(game_infos, game_infos->grid);
	print_grid(game_infos);
	while ((key = getch()) != 27)
	{
		check_key(key, game_infos);
		clear_screen(game_infos);
		print_grid(game_infos);
	}
	free_struct(game_infos);
	endwin();
	return (0);
}
