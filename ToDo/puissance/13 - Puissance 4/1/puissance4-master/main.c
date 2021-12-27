/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <telain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 20:21:52 by telain            #+#    #+#             */
/*   Updated: 2016/02/27 17:06:49 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		find_height(t_value *value, int col)
{
	int		i;

	i = 0;
	while (value->grid[col][i] != ' ')
		i++;
	return (i);
}

t_value	*play(int col, int player, t_value *value)
{
	if (player == 1)
		value->grid[col][find_height(value, col)] = 'x';
	else
		value->grid[col][find_height(value, col)] = 'o';
	return (value);
}

int		main(int ac, char **av)
{
	t_value		*value;
	int			i;

	i = 0;
	if (ac != 3)
		return (0);
	value = create_value(ft_atoi(av[1]), ft_atoi(av[2]));
	ft_putstr("\ntaille en x : ");
	ft_putnendl(value->size_x);
	ft_putstr("\ntaille en y : ");
	ft_putnendl(value->size_y);
	display_grid(value);
	while (i++ < 10)
	{
		value = play(ft_atoi(read_input(value)), 1, value);
		display_grid(value);
		value = play(ft_atoi(read_input(value)), 2, value);
		display_grid(value);
	}
	return (0);	
}
