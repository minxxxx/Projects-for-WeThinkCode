/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 04:51:37 by jtranchi          #+#    #+#             */
/*   Updated: 2016/01/31 18:23:13 by jfrancho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_2048.h"

static void		up_move(t_map *map)
{
	int			y;
	int			x;

	x = -1;
	while (++x < 4)
	{
		y = -1;
		while (++y < 3)
		{
			if (map->tab[y][x] == 0 && map->tab[y + 1][x] != 0)
			{
				map->tab[y][x] = map->tab[y + 1][x];
				map->tab[y + 1][x] = 0;
				y = -1;
			}
		}
	}
}

static void		up_merge(t_map *map)
{
	int			y;
	int			x;

	x = -1;
	while (++x < 4)
	{
		y = -1;
		while (++y < 3)
		{
			if (map->tab[y][x] == map->tab[y + 1][x])
			{
				map->tab[y][x] *= 2;
				map->tab[y + 1][x] = 0;
			}
		}
	}
}

void			up_command(t_map *map)
{
	up_move(map);
	up_merge(map);
	up_move(map);
}
