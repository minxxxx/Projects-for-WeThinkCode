/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 18:27:25 by jfrancho          #+#    #+#             */
/*   Updated: 2016/01/31 20:29:12 by jfrancho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_2048.h"

static int	ft_check_cross(t_map *map)
{
	int y;
	int x;

	y = -1;
	while (++y < 3)
	{
		x = -1;
		while (++x < 3)
			if (map->tab[y][x] == map->tab[y + 1][x] ||
				map->tab[y][x] == map->tab[y][x + 1])
				return (0);
	}
	if (map->tab[3][3] == map->tab[3][2] ||
		map->tab[3][3] == map->tab[2][3])
		return (0);
	return (1);
}

int			ft_check_finish(t_map *map)
{
	int y;
	int x;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			if (map->tab[y][x] == 0)
				return (0);
	}
	return (ft_check_cross(map));
}
