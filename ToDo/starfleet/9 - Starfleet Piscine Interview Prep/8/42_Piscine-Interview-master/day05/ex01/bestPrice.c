/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPrice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:01:53 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/09 16:01:55 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double				max_price = 0.00;

static void			recursiveSlices(double curr, int size, double *prices)
{
	if (size > 0)
	{
		for (int i = size; i > 0; i -= 1)
			recursiveSlices(curr + prices[i], size - i, prices);
	}
	else if (size == 0 && curr > max_price)
		max_price = curr;
	return ;
}

double				bestPrice(int pizzaSize, double *prices)
{
	max_price = prices[pizzaSize];
	for (int i = pizzaSize; i > 0; i -= 1)
		recursiveSlices(0, pizzaSize, prices);
	return (max_price);
}
