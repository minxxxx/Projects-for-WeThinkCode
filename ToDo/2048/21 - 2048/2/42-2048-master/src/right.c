/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 04:37:53 by jtranchi          #+#    #+#             */
/*   Updated: 2016/01/31 18:23:41 by jfrancho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_2048.h"

static void		right_move(t_map *map)
{
	int			y;
	int			x;

	y = -1;
	while (++y < 4)
	{
		x = 4;
		while (--x > 0)
		{
			if (map->tab[y][x] == 0 && map->tab[y][x - 1] != 0)
			{
				map->tab[y][x] = map->tab[y][x - 1];
				map->tab[y][x - 1] = 0;
				x = 4;
			}
		}
	}
}

static void		right_merge(t_map *map)
{
	int			y;
	int			x;

	y = -1;
	while (++y < 4)
	{
		x = 4;
		while (--x > 0)
		{
			if (map->tab[y][x - 1] == map->tab[y][x])
			{
				map->tab[y][x] *= 2;
				map->tab[y][x - 1] = 0;
			}
		}
	}
}

void			right_command(t_map *map)
{
	right_move(map);
	right_merge(map);
	right_move(map);
}
