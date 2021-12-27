/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 10:23:57 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/31 10:23:57 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <string.h>

int			searchPrice(struct s_art **arts, int n, char *name)
{
	int		start;
	int		end;
	int		mid;

	start = 0;
	end = n;
	while (start <= end)
	{
		mid = (end + start) / 2;
		if (strcmp(arts[mid]->name, name) > 0)
			end = mid - 1;
		else if (strcmp(arts[mid]->name, name) < 0)
			start = mid + 1;
		else
			break;
	}
	return (start > end ? -1 : arts[mid]->price);
}
