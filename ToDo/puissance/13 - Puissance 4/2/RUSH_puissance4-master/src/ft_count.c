/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 14:56:07 by geargenc          #+#    #+#             */
/*   Updated: 2017/12/17 22:47:18 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_puissance4.h"

int			ft_count(t_grid *grid, int col, int player)
{
	char	c;
	int		count;

	c = player ? J2 : J1;
	count = ft_countvert(grid, col, c) + ft_counthor(grid, col, c) +
		ft_countrdiag(grid, col, c) + ft_countldiag(grid, col, c);
	return (count);
}
