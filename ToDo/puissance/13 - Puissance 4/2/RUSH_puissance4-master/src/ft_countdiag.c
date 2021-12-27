/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdiag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 22:37:26 by geargenc          #+#    #+#             */
/*   Updated: 2017/12/17 22:38:59 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_puissance4.h"

static int	ft_countrdiagspace(t_grid *grid, int col, char c)
{
	int		count;
	int		j;
	int		k;

	j = ft_playcol(grid, col);
	k = 1;
	while (col + k < grid->width && j + k < grid->height &&
		(grid->grid[j + k][col + k] == c ||
		grid->grid[j + k][col + k] == VOIDCASE))
		k++;
	count = k - 1;
	k = 1;
	while (col - k >= 0 && j - k >= 0 &&
		(grid->grid[j - k][col - k] == c ||
		grid->grid[j - k][col - k] == VOIDCASE))
		k++;
	count = count + k - 1;
	return (count + 1);
}

int			ft_countrdiag(t_grid *grid, int col, char c)
{
	int		count;
	int		j;
	int		k;

	if (ft_countrdiagspace(grid, col, c) < 4)
		return (0);
	j = ft_playcol(grid, col);
	k = 1;
	while (col + k < grid->width && j + k < grid->height &&
		grid->grid[j + k][col + k] == c)
		k++;
	count = k - 1;
	k = 1;
	while (col - k >= 0 && j - k >= 0 && grid->grid[j - k][col - k] == c)
		k++;
	count = count + k - 1;
	return (ft_power(10, count > 3 ? 3 : count));
}

static int	ft_countldiagspace(t_grid *grid, int col, char c)
{
	int		count;
	int		j;
	int		k;

	j = ft_playcol(grid, col);
	k = 1;
	while (col - k >= 0 && j + k < grid->height &&
		(grid->grid[j + k][col - k] == c ||
		grid->grid[j + k][col - k] == VOIDCASE))
		k++;
	count = k - 1;
	k = 1;
	while (col + k < grid->width && j - k >= 0 &&
		(grid->grid[j - k][col + k] == c ||
		grid->grid[j - k][col + k] == VOIDCASE))
		k++;
	count = count + k - 1;
	return (count + 1);
}

int			ft_countldiag(t_grid *grid, int col, char c)
{
	int		count;
	int		j;
	int		k;

	if (ft_countldiagspace(grid, col, c) < 4)
		return (0);
	j = ft_playcol(grid, col);
	k = 1;
	while (col - k >= 0 && j + k < grid->height &&
		grid->grid[j + k][col - k] == c)
		k++;
	count = k - 1;
	k = 1;
	while (col + k < grid->width && j - k >= 0 &&
		grid->grid[j - k][col + k] == c)
		k++;
	count = count + k - 1;
	return (ft_power(10, count > 3 ? 3 : count));
}
