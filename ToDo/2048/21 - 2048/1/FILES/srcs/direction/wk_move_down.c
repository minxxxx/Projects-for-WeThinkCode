/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wk_move_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 14:51:33 by sboulet           #+#    #+#             */
/*   Updated: 2016/01/31 16:49:06 by sboulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

int		wk_move_down(int **grid, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size && (j = size - 1) == size - 1)
		while (--j > -1)
			if (grid[j][i] > 0 && grid[j + 1][i] == 0)
			{
				grid[j + 1][i] = grid[j][i];
				grid[j][i] = 0;
				j = size - 1;
			}
			else if (grid[j][i] > 0 && grid[j][i] == grid[j + 1][i])
			{
				grid[j + 1][i] += grid[j][i];
				grid[j][i] = 0;
			}
	return (1);
}
