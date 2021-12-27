/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapSort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 00:47:58 by smonroe           #+#    #+#             */
/*   Updated: 2019/01/18 21:43:24 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	heap(struct s_art **art, size_t sz, size_t n, size_t i)
{
	size_t cur = i;
	size_t left = (i << 1) + 1;
	size_t right = (i << 1) + 2;

	if (left < n && strcmp(art[left]->name, art[cur]->name) > 0)
		cur = left;
	if (right < n && strcmp(art[right]->name, art[cur]->name) > 0)
		cur = right;
	if (cur ^ i)
	{
		struct s_art *t = art[i];
		art[i] = art[cur];
		art[cur] = t;
		heap(art, sz, n, cur);
	}
}

void heapSort(struct s_art **masterpiece, int n)
{
	for (int i = (n >> 1) - 1; i >= 0; i--)
		heap(masterpiece, sizeof *masterpiece, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		struct s_art *t = masterpiece[0];
		masterpiece[0] = masterpiece[i];
		masterpiece[i] = t;
		heap(masterpiece, sizeof *masterpiece, i, 0);
	}
}
