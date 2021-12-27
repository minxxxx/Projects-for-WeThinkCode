/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printgraphique.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 17:21:24 by thou              #+#    #+#             */
/*   Updated: 2017/12/20 11:02:13 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_puissance4.h"

static void	ft_printend(t_grid *grid)
{
	int	i;

	i = -3;
	while (++i < grid->width)
		ft_putstr("\033[48;5;15;38;5;25;1m  \033[0m");
	ft_putchar('\n');
}

void		ft_printgraphique(t_grid *grid)
{
	int	i;
	int	j;

	ft_printend(grid);
	i = -1;
	while (++i < grid->height)
	{
		ft_putstr("\033[48;5;15;38;5;25;1m  \033[0m");
		j = -1;
		while (++j < grid->width)
		{
			if (grid->grid[i][j] == VOIDCASE)
				ft_putstr("\033[1;30;44m◉ \033[0m");
			if (grid->grid[i][j] == J1)
				ft_putstr("\033[1;33;44m◉ \033[0m");
			if (grid->grid[i][j] == J2)
				ft_putstr("\033[1;31;44m◉ \033[0m");
		}
		ft_putstr("\033[48;5;15;38;5;25;1m  \033[0m\n");
	}
	ft_printend(grid);
}

void		ft_printwing(int fin, int player)
{
	if (fin == 1 && player == 0)
		ft_putendl("\033[46;34mplayer \033[46;1;33m◉ \033[0;46;34m"
			" is the winner!\033[0m");
	else if (fin == 1 && player == 1)
		ft_putendl("\033[46;34mplayer \033[46;1;31m◉ \033[0;46;34m"
			" is the winner!\033[0m");
	else
		ft_putendl("\033[46;34;5m"FULL"\033[0m");
}
