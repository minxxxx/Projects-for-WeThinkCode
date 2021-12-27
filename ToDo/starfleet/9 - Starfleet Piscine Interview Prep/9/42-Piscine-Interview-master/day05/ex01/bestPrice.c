/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPrice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 01:24:08 by amontano          #+#    #+#             */
/*   Updated: 2019/01/16 01:24:09 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	getBest(int pizzaSize, double *prices, double *best, double tmp)
{
	if (!pizzaSize && tmp > *best)
		*best = tmp;
	for (int i = 1; i <= pizzaSize; i++)
		getBest(pizzaSize - i, prices, best, tmp + prices[i]);
}

double bestPrice(int pizzaSize, double *prices)
{
	double best = 0.0;
	for (int i = pizzaSize; i > 0; i--)
		getBest(pizzaSize, prices, &best, 0);
	return (best);
}
