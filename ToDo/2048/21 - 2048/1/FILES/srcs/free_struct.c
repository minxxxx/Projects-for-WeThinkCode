/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:30:14 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/31 15:30:15 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

void	free_struct(t_game_infos *game_infos)
{
	int	**grid;
	int	i;

	grid = game_infos->grid;
	i = -1;
	while (++i < game_infos->size)
		free(grid[i]);
	free(grid);
	grid = NULL;
	clear_screen(game_infos);
	free(game_infos);
}
