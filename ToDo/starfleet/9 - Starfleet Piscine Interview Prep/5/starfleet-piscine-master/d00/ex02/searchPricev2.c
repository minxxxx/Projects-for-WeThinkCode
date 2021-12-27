/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPricev2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:09:15 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/23 16:49:10 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <strings.h>
#include <stdio.h>

static int	binarySearch(struct s_art **arts, int start, int end, char *n)
{
	int	mid;
	int	cmp_result;
	
	if (end >= 1)
	{
		mid = start + (end - start) / 2;
		cmp_result = strcmp(arts[mid]->name, n);
		if (cmp_result == 0)
			return (mid);
		
		if (cmp_result > 0)
			return (binarySearch(arts, start, mid - 1, n));
		else
			return (binarySearch(arts, mid + 1, end, n));
	}
	return (-1);
}

int searchPrice(struct s_art **arts, int n, char *name)
{
	int	index;
	
	index = binarySearch(arts, 0, n - 1, name);
	return ((index == -1) ? -1 : arts[index]->price);
}