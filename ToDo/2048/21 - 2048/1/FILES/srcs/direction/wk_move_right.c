/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wk_move_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:51:57 by sboulet           #+#    #+#             */
/*   Updated: 2016/01/31 16:47:27 by sboulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

int		wk_move_right(int **grid, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size && (j = size - 1) == size - 1)
		while (--j > -1)
			if (grid[i][j] > 0 && grid[i][j + 1] == 0)
			{
				grid[i][j + 1] = grid[i][j];
				grid[i][j] = 0;
				j = size - 1;
			}
			else if (grid[i][j] > 0 && grid[i][j] == grid[i][j + 1])
			{
				grid[i][j + 1] += grid[i][j];
				grid[i][j] = 0;
			}
	return (1);
}
