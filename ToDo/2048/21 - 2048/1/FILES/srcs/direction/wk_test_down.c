/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wk_test_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:06:21 by sboulet           #+#    #+#             */
/*   Updated: 2016/01/30 16:34:00 by sboulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

int		wk_test_down(int **grid, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size && (j = -1))
		while (++j < size - 1)
			if (grid[j][i] > 0 && grid[j + 1][i] == grid[j][i])
				return (1);
			else if (grid[j][i] > 0 && (tmp = j) == j)
				while (++tmp < size)
					if (grid[tmp][i] == 0)
						return (1);
	return (0);
}
