/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotspots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 20:51:48 by amontano          #+#    #+#             */
/*   Updated: 2019/01/16 20:51:57 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int is_overlap(t_hotspot *a, t_hotspot *b)
{
	return (a->pos + a->radius > b->pos - b->radius);
}

int selectHotspots(struct s_hotspot **hotspots)
{
	int			i;
	int			count	= 0;
	t_hotspot	**h		= hotspots;
	int r = 0;
	int len;
	while (hotspots[r + 1])
		r++;
	len = r;
	for (i = 0; h[i + 1]; i++)
	{
		r = len;
		if (is_overlap(h[i], h[i +1]))
		{
			count++;
			if (h[i + 1] && (h[i +1]->radius > h[i]->radius))
				i++;
		}
	}
	return (1 + i - count);
}

