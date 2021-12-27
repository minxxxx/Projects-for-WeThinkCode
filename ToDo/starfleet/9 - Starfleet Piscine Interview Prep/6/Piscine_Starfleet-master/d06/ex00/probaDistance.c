/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   probaDistance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 01:29:30 by smonroe           #+#    #+#             */
/*   Updated: 2019/01/17 01:36:42 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double probaDistance(int dist, int *locations, int n)
{
	long prob[2] = {0};
	register long diff = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++) {
			diff = abs(locations[i] - locations[j]);
			prob[diff > dist ? 0 : 1]++;
		}
	return (double)prob[0] / (double)(prob[0] + prob[1]);
}
