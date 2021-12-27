/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 10:23:57 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/31 10:23:57 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <string.h>

static size_t		getSize(struct s_art **arts)
{
	int				size;

	size = 0;
	while (arts[size] != NULL)
		size += 1;
	return (size);
}

static int			getPartition(struct s_art **arts, int left, int right)
{
	int				i;
	int				j;
	struct s_art	*pivot;
	struct s_art	*tmp;

	i = left;
	j = right;
	pivot = arts[left];
	while (1)
	{
		while (strcmp(arts[i]->name, pivot->name) < 0)
			i += 1;
		while (strcmp(arts[j]->name, pivot->name) > 0)
			j -= 1;
		if (i < j)
		{
			tmp = arts[i];
			arts[i] = arts[j];
			arts[j] = tmp;
			if (strcmp(arts[i]->name, arts[j]->name) == 0)
				j -= 1;
		}
		else
			break;
	}
	return (j);
}

void				quickSort(struct s_art **arts, int left, int right)
{
	int				partition;

	if (left < right)
	{
		partition = getPartition(arts, left, right);
		quickSort(arts, left, partition);
		quickSort(arts, partition + 1, right);
	}
	return ;
}

void  				sortArts(struct s_art **arts)
{
	return (quickSort(arts, 0, getSize(arts) - 1));
}
