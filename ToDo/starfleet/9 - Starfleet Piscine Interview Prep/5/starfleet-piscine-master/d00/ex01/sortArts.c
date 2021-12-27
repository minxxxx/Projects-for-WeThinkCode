/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 02:14:29 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/25 02:57:54 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <strings.h>

static	void	swapArts(struct s_art **a, struct s_art **b)
{
	struct s_art *tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

static	int		partition(struct s_art **arts, int low, int high)
{
	char	*pivot;
	int		i;

	pivot = arts[high]->name;
	i = low - 1;
	for (int j = low; j <= high- 1; j++)
    {
        if (strcmp(arts[j]->name, pivot) <= 0)
            swapArts(&arts[++i], &arts[j]);
    }
    swapArts(&arts[i + 1], &arts[high]);
    return (i + 1);
}

static	void	quickSort(struct s_art **arts, int low, int high)
{
	int partition_index;

	if (low < high)
	{
		partition_index = partition(arts, low, high);
		quickSort(arts, low, partition_index - 1);
		quickSort(arts, partition_index + 1, high);
	}
}

// Only way to figure out length of array. O(1) to figure out length of array

static int		arr_len(struct s_art **arts)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (arts[++i])
		len++;
	return (len);
}

void	sortArts(struct s_art **arts)
{
	int	len;

	len = arr_len(arts);
	quickSort(arts, 0, len - 1);
}