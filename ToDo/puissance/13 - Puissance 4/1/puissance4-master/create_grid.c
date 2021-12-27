/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <telain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 20:34:56 by telain            #+#    #+#             */
/*   Updated: 2016/02/26 23:25:50 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

t_value		*fill(t_value *value)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < value->size_y)
	{
		while (x < value->size_x)
		{
			value->grid[y][x] = ' ';
			x++;
		}
		x = 0;
		y++;
	}
	return (value);
}

t_value		*create_grid(t_value *value)
{
	int		i;

	i = 0;
	value->grid = (int**)malloc(sizeof(int*) * (value->size_y + 1));
	while (i <= value->size_y)
		value->grid[i++] = (int*)malloc(sizeof(int) * (value->size_x + 100));
	value = fill(value);
	return (value);
}

t_value		*create_value(int size_x, int size_y)
{
	t_value		*new;

	new = malloc(sizeof(t_value));
	new->size_x = size_x;
	new->size_y = size_y;
	new = create_grid(new);
	return (new);
}
