/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 03:11:45 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/25 23:22:41 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>
#include <stdio.h>

static	struct s_player	**new_arr(int size)
{
	int				i;
	struct s_player	**player;

	i = -1;
	player = calloc(size + 1, sizeof(struct s_player *));
	while (++i < size)
		player[i] = calloc(1, sizeof(struct s_player));
	player[i] = NULL;
	return (player);
}

static	void	merge(struct s_player **players, int start, int middle, int end, struct s_player ***sorted_player)
{
	int	i, j, k;
	int	size_left, size_right;

	size_left = middle - start + 1;
	size_right = end - middle;

	struct s_player	*left_array[size_left];
	struct s_player	*right_array[size_right];
	struct s_player **final_arr;

	final_arr = *sorted_player;
	i = -1;
	j = -1;
	while (++i < size_left)
		left_array[i] = players[start + i];
	while (++j < size_right)
		right_array[i] = players[middle + 1 + j];
	i = 0;
	j = 0;
	k = 0;
	write(1, "a\n", 2);
	printf("i: %d, j: %d, k: %d, size_l: %d, size_r: %d\n", i, j, k, size_left, size_right);
	// fflush(stdout);
	while (i < size_left && j < size_right)
	{
		if (right_array[j]->score > left_array[i]->score)
			players[k++] = right_array[j++];
		else if (right_array[j]->score == left_array[i]->score)
		{
			if (right_array[j]->timeStamp > left_array[i]->timeStamp)
			final_arr[k++] = right_array[j++];
		}
		else
			final_arr[k++] = left_array[i++];
	}
}

static	struct s_player	**mergeSortAlgo(struct s_player **players, int start, int end)
{
	struct s_player **sorted_player;
	
	sorted_player = new_arr(end + 1);
	if (start < end)
	{
		int	middle;
		middle = start + (end - start) / 2;
		mergeSortAlgo(players, start, middle);
		mergeSortAlgo(players, middle + 1, end);

		merge(players, start, end, middle, &sorted_player);
	}
	return (sorted_player);
}

static int		arrLen(struct s_player **players)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (players[++i])
		len++;
	return (len);
}

struct s_player **mergeSort(struct s_player **players)
{
	int	len;
	struct s_player **sorted_player;
	
	len = arrLen(players);
	sorted_player = mergeSortAlgo(players, 0, len - 1);
	return (sorted_player);
}