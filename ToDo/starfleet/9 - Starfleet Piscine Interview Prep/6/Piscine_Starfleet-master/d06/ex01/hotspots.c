/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotspots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 01:41:56 by smonroe           #+#    #+#             */
/*   Updated: 2019/01/17 08:39:56 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int selectHotspots(struct s_hotspot **hotspots)
{
	if (!hotspots || !(*hotspots))
		return 0;
	int n = 0, i;
	for (i = 0; hotspots[i + 1]; i++)
	{
		if ((hotspots[i]->pos + hotspots[i]->radius) > (hotspots[i + 1]->pos - hotspots[i + 1]->radius))
		{
			n++;
			if (hotspots[i]->radius <= hotspots[i + 1]->radius)
				i++;
		}
	}
	return 1 + i - n;
}


