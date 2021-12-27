/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wk_test_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:02:17 by sboulet           #+#    #+#             */
/*   Updated: 2016/01/31 15:09:06 by sboulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

int		wk_test_left(int **grid, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size && (j = size))
		while (--j > 0)
			if (grid[i][j] > 0 && grid[i][j - 1] == grid[i][j])
				return (1);
			else if (grid[i][j] > 0 && (tmp = j) == j)
				while (--tmp > -1)
					if (grid[i][tmp] == 0)
						return (1);
	return (0);
}
