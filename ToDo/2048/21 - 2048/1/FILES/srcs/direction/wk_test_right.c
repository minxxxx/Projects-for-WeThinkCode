/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wk_test_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 12:39:47 by sboulet           #+#    #+#             */
/*   Updated: 2016/01/30 16:32:57 by sboulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

int		wk_test_right(int **grid, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size && (j = -1))
		while (++j < size - 1)
			if (grid[i][j] > 0 && grid[i][j + 1] == grid[i][j])
				return (1);
			else if (grid[i][j] > 0 && (tmp = j) == j)
				while (++tmp < size)
					if (grid[i][tmp] == 0)
						return (1);
	return (0);
}
