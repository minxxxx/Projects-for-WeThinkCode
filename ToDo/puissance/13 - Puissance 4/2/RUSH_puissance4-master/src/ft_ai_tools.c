/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ai_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 22:43:43 by geargenc          #+#    #+#             */
/*   Updated: 2017/12/17 22:44:30 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_puissance4.h"

void		ft_simufill(t_grid *grid, int col, int player)
{
	char	c;

	c = player ? J2 : J1;
	grid->grid[ft_playcol(grid, col)][col] = c;
}

void		ft_delcoup(t_grid *grid, int col)
{
	grid->grid[ft_playcol(grid, col) + 1][col] = VOIDCASE;
}
