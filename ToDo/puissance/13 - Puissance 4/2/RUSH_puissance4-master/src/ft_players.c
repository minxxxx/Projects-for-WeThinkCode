/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_players.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 22:47:26 by geargenc          #+#    #+#             */
/*   Updated: 2017/12/17 22:56:22 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_puissance4.h"

int			ft_ai1(t_grid *grid, int player)
{
	return (ft_ai(grid, player, 1));
}

int			ft_ai2(t_grid *grid, int player)
{
	return (ft_ai(grid, player, 2));
}

int			ft_ai3(t_grid *grid, int player)
{
	return (ft_ai(grid, player, 4));
}

int			ft_ai4(t_grid *grid, int player)
{
	return (ft_ai(grid, player, 6));
}
