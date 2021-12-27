/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 04:37:37 by jtranchi          #+#    #+#             */
/*   Updated: 2016/01/31 18:22:57 by jfrancho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_2048.h"

static void		down_move(t_map *map)
{
	int			y;
	int			x;

	x = -1;
	while (++x < 4)
	{
		y = 4;
		while (--y > 0)
		{
			if (map->tab[y][x] == 0 && map->tab[y - 1][x] != 0)
			{
				map->tab[y][x] = map->tab[y - 1][x];
				map->tab[y - 1][x] = 0;
				y = 4;
			}
		}
	}
}

static void		down_merge(t_map *map)
{
	int			y;
	int			x;

	x = -1;
	while (++x < 4)
	{
		y = 4;
		while (--y > 0)
		{
			if (map->tab[y][x] == map->tab[y - 1][x])
			{
				map->tab[y][x] *= 2;
				map->tab[y - 1][x] = 0;
			}
		}
	}
}

void			down_command(t_map *map)
{
	down_move(map);
	down_merge(map);
	down_move(map);
}
