/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkwin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 12:28:57 by geargenc          #+#    #+#             */
/*   Updated: 2017/12/17 12:08:48 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_puissance4.h"

static int	ft_checkvert(t_grid *grid, int j, int i, char c)
{
	int		nbr;

	if (j != 0 && grid->grid[j - 1][i] == c)
		return (0);
	nbr = 0;
	while (j + nbr < grid->height && grid->grid[j + nbr][i] == c)
		nbr++;
	return (nbr);
}

static int	ft_checkhor(t_grid *grid, int j, int i, char c)
{
	int		nbr;

	if (i != 0 && grid->grid[j][i - 1] == c)
		return (0);
	nbr = 0;
	while (i + nbr < grid->width && grid->grid[j][i + nbr] == c)
		nbr++;
	return (nbr);
}

static int	ft_checkrdiag(t_grid *grid, int j, int i, char c)
{
	int		nbr;

	if (i != 0 && j != 0 && grid->grid[j - 1][i - 1] == c)
		return (0);
	nbr = 0;
	while (j + nbr < grid->height && i + nbr < grid->width &&
		grid->grid[j + nbr][i + nbr] == c)
		nbr++;
	return (nbr);
}

static int	ft_checkldiag(t_grid *grid, int j, int i, char c)
{
	int		nbr;

	if (i != grid->width - 1 && j != 0 && grid->grid[j - 1][i + 1] == c)
		return (0);
	nbr = 0;
	while (j + nbr < grid->height && i - nbr >= 0 &&
		grid->grid[j + nbr][i - nbr] == c)
		nbr++;
	return (nbr);
}

int			ft_checkwin(t_grid *grid, int player)
{
	unsigned char	c;
	int				j;
	int				i;

	c = (player) ? J2 : J1;
	j = 0;
	while (j < grid->height)
	{
		i = 0;
		while (i < grid->width)
		{
			if (grid->grid[j][i] == c)
			{
				if (ft_checkvert(grid, j, i, c) >= 4 ||
					ft_checkhor(grid, j, i, c) >= 4 ||
					ft_checkrdiag(grid, j, i, c) >= 4 ||
					ft_checkldiag(grid, j, i, c) >= 4)
					return (1);
			}
			i++;
		}
		j++;
	}
	return (ft_checkfull(grid) ? -1 : 0);
}
