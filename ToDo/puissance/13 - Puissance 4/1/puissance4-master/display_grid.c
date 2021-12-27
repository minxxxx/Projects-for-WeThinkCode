/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <telain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 21:16:53 by telain            #+#    #+#             */
/*   Updated: 2016/02/27 16:49:36 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void	write_case(t_value *value, int x, int y)
{
	ft_putstr("| ");
	if (value->grid[x][y] == 'x')
		ft_putstr("\033[1;33m");
	else if (value->grid[x][y] == 'o')
		ft_putstr("\033[1;31m");
	else
		ft_putstr("\033[0;0m");
	ft_putchar(value->grid[x][y]);
	ft_putstr("\033[0;0m");
	ft_putstr(" |");
}

void	display_grid(t_value *value)
{
	int		x;
	int		y;

	x = 0;
	y = value->size_y - 1;
	while (y >= 0)
	{
			ft_putchar('|');
		while (x < value->size_x)
		{
			write_case(value, x, y);
			x++;
		}
		ft_putstr("|\n------------------------------------\n");
		y--;
		x = 0;
	}
	ft_putstr("\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\");
}
