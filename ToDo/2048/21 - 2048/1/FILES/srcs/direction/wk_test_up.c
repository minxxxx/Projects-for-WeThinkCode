/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wk_test_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:09:47 by sboulet           #+#    #+#             */
/*   Updated: 2016/01/31 15:12:12 by sboulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

int		wk_test_up(int **grid, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size && (j = size))
		while (--j > 0)
			if (grid[j][i] > 0 && grid[j - 1][i] == grid[j][i])
				return (1);
			else if (grid[j][i] > 0 && (tmp = j) == j)
				while (--tmp > -1)
					if (grid[tmp][i] == 0)
						return (1);
	return (0);
}
