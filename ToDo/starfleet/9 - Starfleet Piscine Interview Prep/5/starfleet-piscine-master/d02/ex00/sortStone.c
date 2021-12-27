/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 01:32:05 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/25 02:24:54 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	bubbleSort(struct s_list **stone)
{
	struct s_list	*tmp1;
	struct s_list	*tmp2;
	
	tmp1 = *stone;
	while (tmp1->next)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->size > tmp2->size)
				swapStones(&tmp1->size, &tmp2->size, &tmp1->amount, &tmp2->amount);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

void	newNode(struct s_list **list, int n)
{
	struct s_list	*new;
	
	new = calloc(1, sizeof(struct s_list));
	new->size = n;
	new->amount = 1;
	new->next = *list;
	*list = new;
}

void	swapStones(int *a1, int *b1, int *a2, int *b2)
{
	int tmp1;

	tmp1 = *a1;
	*a1 = *b1;
	*b1 = tmp1;

	int tmp2;

	tmp2 = *a2;
	*a2 = *b2;
	*b2 = tmp2;
}

struct s_list *new_list(struct s_stone *stone)
{
	struct s_list	*list;
	struct s_stone	*tmp;
	int				prev;
	
	list = NULL;
	tmp = stone;
	prev = tmp->size;
	list = calloc(1, sizeof(struct s_list));
	list->size = tmp->size;
	list->amount = 0;
	list->next = NULL;
	while (tmp)
	{
		if (tmp->size != prev)
			newNode(&list, tmp->size);
		else
			list->amount++;
		prev = tmp->size;
		tmp = tmp->next;
	}
	return (list);
}

void sortStones(struct s_stone **stone)
{
	struct s_list	*cooler_list;
	struct s_list	*tmp_cool;
	struct s_stone	*tmp_boring;
	int				i;

	cooler_list = new_list(*stone);
	bubbleSort(&cooler_list);
	tmp_cool = cooler_list;
	tmp_boring = *stone;
	while(tmp_cool)
	{
		i = -1;
		while (++i < tmp_cool->amount)
		{
			tmp_boring->size = tmp_cool->size;
			tmp_boring = tmp_boring->next;
		}
		tmp_cool = tmp_cool->next;
	}
}

// void	swapStones(int *a1, int *b1)
// {
// 	int tmp1;

// 	tmp1 = *a1;
// 	*a1 = *b1;
// 	*b1 = tmp1;
// }

// 	// Regular bubble sort implementation
// void	sortStones(struct s_stone **stone)
// {
// 	struct s_stone	*tmp1;
// 	struct s_stone	*tmp2;
	
// 	tmp1 = *stone;
// 	while (tmp1->next)
// 	{
// 		tmp2 = tmp1->next;
// 		while (tmp2)
// 		{
// 			if (tmp1->size > tmp2->size)
// 				swapStones(&tmp1->size, &tmp2->size);
// 			tmp2 = tmp2->next;
// 		}
// 		tmp1 = tmp1->next;
// 	}
// }