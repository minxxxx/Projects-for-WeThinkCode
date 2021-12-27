/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countvh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 22:33:34 by geargenc          #+#    #+#             */
/*   Updated: 2017/12/17 22:34:28 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_puissance4.h"

static int	ft_countvertspace(t_grid *grid, int col, char c)
{
	int		count;
	int		j;
	int		k;

	j = ft_playcol(grid, col);
	k = 1;
	while (j + k < grid->height && grid->grid[j + k][col] == c)
		k++;
	count = k - 1;
	k = 1;
	while (j - k >= 0 && grid->grid[j - k][col] == VOIDCASE)
		k++;
	count = count + k - 1;
	return (count + 1);
}

int			ft_countvert(t_grid *grid, int col, char c)
{
	int		count;
	int		j;
	int		k;

	if (ft_countvertspace(grid, col, c) < 4)
		return (0);
	j = ft_playcol(grid, col);
	k = 1;
	while (j + k < grid->height && grid->grid[j + k][col] == c)
		k++;
	count = k - 1;
	return (ft_power(10, count > 3 ? 3 : count));
}

static int	ft_counthorspace(t_grid *grid, int col, char c)
{
	int		count;
	int		j;
	int		k;

	j = ft_playcol(grid, col);
	k = 1;
	while (col + k < grid->width && (grid->grid[j][col + k] == c ||
		grid->grid[j][col + k] == VOIDCASE))
		k++;
	count = k - 1;
	k = 1;
	while (col - k >= 0 && (grid->grid[j][col - k] == c ||
		grid->grid[j][col - k] == VOIDCASE))
		k++;
	count = count + k - 1;
	return (count + 1);
}

int			ft_counthor(t_grid *grid, int col, char c)
{
	int		count;
	int		j;
	int		k;

	if (ft_counthorspace(grid, col, c) < 4)
		return (0);
	j = ft_playcol(grid, col);
	k = 1;
	while (col + k < grid->width && grid->grid[j][col + k] == c)
		k++;
	count = k - 1;
	k = 1;
	while (col - k >= 0 && grid->grid[j][col - k] == c)
		k++;
	count = count + k - 1;
	return (ft_power(10, count > 3 ? 3 : count));
}
