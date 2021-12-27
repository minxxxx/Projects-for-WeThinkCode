/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 20:55:46 by jfrancho          #+#    #+#             */
/*   Updated: 2016/01/31 18:23:28 by jfrancho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_2048.h"

static void		left_move(t_map *map)
{
	int			i;
	int			j;

	j = 0;
	while (j <= 3)
	{
		i = 0;
		while (i < 3)
		{
			if (map->tab[j][i] == 0 && map->tab[j][i + 1] != 0)
			{
				map->tab[j][i] = map->tab[j][i + 1];
				map->tab[j][i + 1] = 0;
				i = -1;
			}
			i++;
		}
		j++;
	}
}

static void		left_merge(t_map *map)
{
	int			i;
	int			j;

	j = 0;
	while (j <= 3)
	{
		i = 0;
		while (i < 3)
		{
			if (map->tab[j][i] == map->tab[j][i + 1])
			{
				map->tab[j][i] *= 2;
				map->tab[j][i + 1] = 0;
			}
			i++;
		}
		j++;
	}
}

void			left_command(t_map *map)
{
	left_move(map);
	left_merge(map);
	left_move(map);
}
