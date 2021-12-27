/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wk_move_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 14:55:24 by sboulet           #+#    #+#             */
/*   Updated: 2016/01/31 16:49:15 by sboulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

int		wk_move_up(int **grid, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size && (j = 0) == 0)
		while (++j < size)
			if (grid[j][i] > 0 && grid[j - 1][i] == 0)
			{
				grid[j - 1][i] = grid[j][i];
				grid[j][i] = 0;
				j = 0;
			}
			else if (grid[j][i] > 0 && grid[j][i] == grid[j - 1][i])
			{
				grid[j - 1][i] += grid[j][i];
				grid[j][i] = 0;
			}
	return (1);
}
