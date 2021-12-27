/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sinkIsland.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:03:16 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/09 16:03:16 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

void	sinkIsland(int **map, int row, int col)
{
	if ((row >= 0 && col >= 0) && (map[row][col] == 1) && (map[row] != NULL))
	{
		map[row][col] = 0;
		sinkIsland(map, row, col - 1);
		sinkIsland(map, row, col + 1);
		sinkIsland(map, row + 1, col);
		sinkIsland(map, row - 1, col);
	}
	return ;
}
