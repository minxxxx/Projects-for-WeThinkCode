/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPriceV2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:03:00 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/09 16:03:01 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

static double		recursiveSlices(int size, double *best, double *prices)
{
	double			tmp;

	if (best[size] == 0)
	{
		best[size] = prices[size];
		for (int i = 1; i <= size / 2; i += 2)
		{
			tmp = recursiveSlices(i, best, prices) \
					+ recursiveSlices(size - i, best, prices);
			best[size] = (tmp > best[size]) ? tmp : best[size];
		}
	}
	return (best[size]);
}

double				optimizedBestPrice(int pizzaSize, double *prices)
{
	double			*best;

	best = malloc(sizeof(double) * pizzaSize);
	for (int i = 0; i <= pizzaSize; i += 1)
		best[i] = 0;
	return (recursiveSlices(pizzaSize, best, prices));
}
