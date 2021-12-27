/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_human.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 11:31:26 by geargenc          #+#    #+#             */
/*   Updated: 2017/12/17 21:21:06 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_puissance4.h"

int				ft_human(t_grid *grid, int player)
{
	char		*line;
	int			ans;

	(void)player;
	ans = 0;
	while (ans < 1 || ans > grid->width || grid->grid[0][ans - 1] != VOIDCASE)
	{
		ft_putstr("Where do you want to play ? (1 to ");
		ft_putnbr(grid->width);
		ft_putstr(")\n");
		if (get_next_line(0, &line) < 0)
			return (0);
		ans = ft_atoi(line);
		free(line);
		if (ans == 0)
		{
			grid->graphique = 1 - grid->graphique;
			ft_printgrid(grid);
		}
		else if (ans < 1 || ans > grid->width)
			ft_putstr("Invalid answer\n");
		else if (grid->grid[0][ans - 1] != VOIDCASE)
			ft_putstr("Column is full\n");
	}
	return (ans);
}
