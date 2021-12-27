/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wk_move_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:51:57 by sboulet           #+#    #+#             */
/*   Updated: 2016/01/31 16:48:55 by sboulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

int		wk_move_left(int **grid, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size && (j = 0) == 0)
		while (++j < size)
			if (grid[i][j] > 0 && grid[i][j - 1] == 0)
			{
				grid[i][j - 1] = grid[i][j];
				grid[i][j] = 0;
				j = 0;
			}
			else if (grid[i][j] > 0 && grid[i][j] == grid[i][j - 1])
			{
				grid[i][j - 1] += grid[i][j];
				grid[i][j] = 0;
			}
	return (1);
}
