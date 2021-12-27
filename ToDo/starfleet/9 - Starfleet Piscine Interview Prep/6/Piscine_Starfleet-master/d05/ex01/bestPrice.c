/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPrice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 06:38:40 by smonroe           #+#    #+#             */
/*   Updated: 2019/01/16 08:37:11 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rec(double this, int size, double *prices, double *best)
{
	if (size == 0 && this > *best)
		*best = this;
	if (size > 0)
		for (int i = size; i > 0; i--)
			rec(prices[i] + this, size - i, prices, best);
}

double bestPrice(int pizzaSize, double *prices)
{
	double best = prices[pizzaSize];
	for (int i = pizzaSize; i > 0; i--)
		rec(0, pizzaSize, prices, &best);
	return best;
}
