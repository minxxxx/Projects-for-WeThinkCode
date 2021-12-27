/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 20:40:48 by jfrancho          #+#    #+#             */
/*   Updated: 2016/01/31 20:06:47 by jfrancho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_2048.h"

static void			ft_check_score(t_map *map)
{
	int y;
	int x;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (map->tab[y][x] >= WIN_VALUE)
			{
				endwin();
				ft_putendl("YOU WIN!");
				exit(0);
			}
		}
	}
}

static void			initialise(t_map *map)
{
	initscr();
	start_color();
	init_map(map);
	fill_with_rand(map, 2);
	ft_save(map);
	print_map(map);
}

static void			key_commander(t_map *map, int k)
{
	if (k == KEY_LEFT)
		left_command(map);
	else if (k == KEY_RIGHT)
		right_command(map);
	else if (k == KEY_UP)
		up_command(map);
	else if (k == KEY_DOWN)
		down_command(map);
	if (!ft_diff_save(map))
	{
		fill_with_rand(map, 1);
		ft_save(map);
	}
	if (ft_check_finish(map) && ft_diff_save(map))
	{
		endwin();
		ft_putendl("YOU LOSE!");
		exit(0);
	}
	ft_check_score(map);
	clear();
	refresh();
	print_map(map);
}

int					main(void)
{
	int				k;
	struct s_map	*map;

	k = 0;
	if (!(map = (t_map *)malloc(sizeof(t_map))) || (test_errors() == 0))
		return (0);
	initialise(map);
	while (k != 27)
	{
		k = getch();
		move(0, 0);
		key_commander(map, k);
	}
	endwin();
	return (0);
}
