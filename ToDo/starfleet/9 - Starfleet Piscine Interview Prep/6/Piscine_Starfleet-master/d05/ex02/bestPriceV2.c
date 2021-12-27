/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPriceV2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <smonroe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 07:57:27 by smonroe           #+#    #+#             */
/*   Updated: 2019/01/16 23:27:06 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#define SZ 200
double	rec(double this, int size, double *prices, double *best, double (*memo)[SZ])
{
	if ((*memo)[size])
		return (*memo[size]);
	if (size == 0 && this > *best)
		*best = this;
	if (size > 0)
		for (int i = size; i > 0; i--)
			rec(prices[i] + this, size - i, prices, best, memo);
}

double optimizedBestPrice(int pizzaSize, double *prices)
{
	double best = prices[pizzaSize];
	static double memo[SZ];
	if (!memo[pizzaSize])
		return rec(0, pizzaSize, prices, &best, &memo);
	return memo[pizzaSize];
}
