/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 13:53:43 by smonroe           #+#    #+#             */
/*   Updated: 2019/01/07 16:22:21 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int searchPrice(struct s_art **arts, int n, char *name) { return binary_search(arts, 0, n, name); }

int binary_search(struct s_art **arts, int start, int end, char *name)
{
	int cmp, mid;
	while (end >= 1 && end > start)
	{
		mid = (start + end) / 2;
		if (arts[mid])
			cmp = strcmp(name, arts[mid]->name);
		else
			return -1;
		if (!cmp)
			return arts[mid]->price;
		if (cmp > 0)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return -1;
}
