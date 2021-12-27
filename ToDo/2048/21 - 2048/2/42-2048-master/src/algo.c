/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 14:28:04 by jfrancho          #+#    #+#             */
/*   Updated: 2016/01/31 18:22:10 by jfrancho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_2048.h"

static int	find_freespot(t_map *map, int *rand1, int *rand2, int casechecked)
{
	while (map->tab[*rand1][*rand2] != 0 && casechecked < 16)
	{
		if (*rand1 == 3 && *rand2 == 3)
		{
			*rand1 = 0;
			*rand2 = 0;
		}
		else if (*rand2 == 3)
		{
			*rand2 = 0;
			(*rand1)++;
		}
		else
			(*rand2)++;
		casechecked++;
	}
	if (casechecked == 16)
	{
		ft_putendl("You lose!");
		return (0);
	}
	return (1);
}

int			fill_with_rand(t_map *map, int len)
{
	int		random_2_4;
	int		random1;
	int		random2;

	srand(time(NULL));
	while (len > 0)
	{
		random_2_4 = 2 * (1 + rand() % 2);
		random1 = rand() % 4;
		random2 = rand() % 4;
		find_freespot(map, &random1, &random2, 0);
		if (map->tab[random1][random2] == 0)
			map->tab[random1][random2] = random_2_4;
		len--;
		if (len == 0)
			print_map(map);
	}
	return (1);
}
