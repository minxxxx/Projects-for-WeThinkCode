/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 02:56:02 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/26 07:27:57 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static	void	swapArts(struct s_player **a, struct s_player **b)
{
	struct s_player *tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

static	int		partition(struct s_player **players, int low, int high)
{
	int		pivot;
	int		i;

	pivot = players[high]->score;
	i = low - 1;
	for (int j = low; j <= high- 1; j++)
    {
        if (players[j]->score > pivot)
            swapArts(&players[++i], &players[j]);
    }
    swapArts(&players[i + 1], &players[high]);
    return (i + 1);
}

static	void	quickSortAlgo(struct s_player **players, int low, int high)
{
	int partition_index;

	if (low < high)
	{
		partition_index = partition(players, low, high);
		quickSortAlgo(players, low, partition_index - 1);
		quickSortAlgo(players, partition_index + 1, high);
	}
}

void	quickSort(struct s_player **players)
{
	int	len;

	len = arrLen(players);
	quickSortAlgo(players, 0, len - 1);
}