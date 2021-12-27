/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 02:33:55 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/25 16:36:46 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void insertionSort(struct s_player **players)
{
	int				i;
	int				j;
	struct s_player	*key;

	i = j = -1;
	while (players[++i])
	{
		key = players[i];
		j = i;
		while (--j >= 0 && (players[j]->score < key->score))
			players[j + 1] = players [j];
		players[j + 1] = key;
	}
}
