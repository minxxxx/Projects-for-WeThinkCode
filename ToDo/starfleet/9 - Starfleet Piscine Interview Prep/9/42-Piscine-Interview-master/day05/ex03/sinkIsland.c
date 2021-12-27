/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sinkIsland.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 03:43:25 by amontano          #+#    #+#             */
/*   Updated: 2019/01/16 03:43:27 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void sinkIsland(int **map, int row, int col)
{
	if (row >= 0 && col >= 0 && map[row] && map[row][col] == 1)
	{
		map[row][col] = 0;
		sinkIsland(map, row + 1, col);
		sinkIsland(map, row - 1, col);
		sinkIsland(map, row, col + 1);
		sinkIsland(map, row, col - 1);
	}
}


