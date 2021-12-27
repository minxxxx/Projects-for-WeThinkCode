/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:19:28 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/31 16:58:17 by sboulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

static int	generate_number(void)
{
	int		nb;

	srand((unsigned)time(NULL));
	nb = rand() % 10;
	if (nb % 2 == 0)
		return (2);
	else
		return (4);
}

int			place_number(t_game_infos *game_infos)
{
	int		free_spots;
	int		row;
	int		col;

	free_spots = 0;
	row = -1;
	while (++row < game_infos->size && (col = -1))
		while (++col < game_infos->size)
			free_spots += (game_infos->grid)[row][col] == 0 ? 1 : 0;
	srand((unsigned)time(NULL));
	free_spots = rand() % free_spots;
	row = -1;
	while (++row < game_infos->size && (col = -1))
		while (++col < game_infos->size)
			if (free_spots == 0 && (game_infos->grid)[row][col] == 0)
			{
				(game_infos->grid)[row][col] = generate_number();
				return (1);
			}
			else if ((game_infos->grid)[row][col] == 0)
				free_spots--;
	return (0);
}
