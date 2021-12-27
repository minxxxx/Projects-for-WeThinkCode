/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillgrid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 12:25:42 by thou              #+#    #+#             */
/*   Updated: 2017/12/17 23:08:06 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_puissance4.h"

void	ft_printgrid(t_grid *grid)
{
	int	col;
	int	j;

	if (grid->graphique == 1)
	{
		ft_printgraphique(grid);
		return ;
	}
	col = 0;
	while (col < grid->height)
	{
		ft_putchar('|');
		write(1, grid->grid[col], grid->width);
		ft_putstr("|\n");
		col++;
	}
	ft_putchar('+');
	j = grid->width;
	while (--j >= 0)
		ft_putchar('-');
	ft_putstr("+\n");
}

void	ft_fillgrid(int player, int ans, t_grid *grid)
{
	int	height;

	height = 0;
	while (height < grid->height && grid->grid[height][ans - 1] == VOIDCASE)
		height++;
	if (player == 0)
		grid->grid[height - 1][ans - 1] = J1;
	else
		grid->grid[height - 1][ans - 1] = J2;
	ft_printgrid(grid);
}
