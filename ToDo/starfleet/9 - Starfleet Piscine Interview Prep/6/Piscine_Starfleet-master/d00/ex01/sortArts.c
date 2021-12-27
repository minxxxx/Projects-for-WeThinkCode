/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 09:46:53 by smonroe           #+#    #+#             */
/*   Updated: 2019/01/08 23:38:26 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void swap(struct s_art **a, struct s_art **b)
{
	struct s_art *tmp = *a;
	*a = *b;
	*b = tmp;
}

void quick(struct s_art **arts, unsigned int n) // O(n log n)?
{
	unsigned int i, piv = 0;

	if (n <= 1)
		return ;
	swap(arts + ((unsigned int)rand() % n), arts + n - 1);
	for (i = 0; i < n - 1; ++i) // O(n)
		if (strcmp(arts[i]->name, arts[n - 1]->name) < 0)
			swap(arts + i, arts + piv++);
	swap(arts + piv, arts + n - 1);
	quick(arts, piv++);
	quick(arts + piv, n - piv); // O(log n)
}

void	sortArts(struct s_art **arts)
{
	unsigned int i = -1;
	while (arts[++i]);
	quick(arts, i);
}
