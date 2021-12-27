/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPriceV2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 03:30:57 by amontano          #+#    #+#             */
/*   Updated: 2019/01/16 03:30:59 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define MAX(a,b) (a > b) ? a : b

double get_best(int n, double *prices, double *best)
{
	if (best[n] == 0)
	{
		double tmp;

		best[n] = prices[n];
		for (int i = 1; i <= n / 2; i += 2)
		{
			tmp = get_best(i, prices, best) + get_best(n - i, prices, best);
			best[n] = MAX(tmp, best[n]);
		}
	}
	return (best[n]);
}

double optimizedBestPrice(int pizzaSize, double *prices)
{
	double *best = malloc((pizzaSize + 1) * sizeof(double));

	memset(best, 0, pizzaSize + 1);
	return (get_best(pizzaSize, prices, best));
}
