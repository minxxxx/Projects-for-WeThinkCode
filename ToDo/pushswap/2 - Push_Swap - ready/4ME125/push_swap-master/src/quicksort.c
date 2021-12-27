/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:16:00 by alucas-           #+#    #+#             */
/*   Updated: 2018/03/12 18:16:02 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int		keeprotate(t_ps *ps, uint8_t stack, uint32_t n, int64_t pivot)
{
	t_psnode *node;

	if (!(node = ps_head(ps, stack)))
		return (0);
	while (n--)
	{
		if (((int64_t)node->val * ps->orders[stack]) < pivot)
			return (1);
		node = node->next;
	}
	return (0);
}

static int64_t	getpivot(t_ps *ps, uint8_t stack, uint32_t n)
{
	t_psnode	*node;
	int64_t		min;
	int64_t		max;
	int64_t		pivot;

	if (!(node = ps_head(ps, stack)))
		return (0);
	max = 0;
	min = UINT32_MAX;
	while (n-- && node != (t_psnode *)(ps->stacks + stack))
	{
		if (node->val > max)
			max = node->val;
		if (node->val < min)
			min = node->val;
		node = node->next;
	}
	pivot = (int64_t)(((max - min) / 2) + min) * ps->orders[stack];
	return (pivot + 1);
}

void			ps_quicksort(t_ps *ps, uint8_t stack, uint32_t n)
{
	uint32_t	push;
	uint32_t	rotate;
	int64_t		pivot;
	uint32_t	i;

	i = 0;
	push = 0;
	rotate = 0;
	pivot = getpivot(ps, stack, n);
	while (keeprotate(ps, stack, n, pivot) && i++ < n)
		if (((int64_t)ps_head(ps, stack)->val * ps->orders[stack]) < pivot)
			ps_pop(ps, (uint8_t)(stack + (++push & 0)));
		else
			ps_rotate(ps, (uint8_t)(stack + (++rotate & 0)));
	stack ? ps_sort(ps, (uint8_t)(stack ^ 1), push) : 0;
	if (rotate > ps->stacks[stack].len / 2 && ps->stacks[stack].len > 3)
		while (rotate++ < ps->stacks[stack].len)
			ps_rotate(ps, stack);
	else if (ps->stacks[stack].len > 3)
		while (rotate--)
			ps_rrotate(ps, stack);
	ps_sort(ps, stack, n - push);
	!stack ? ps_sort(ps, (uint8_t)(stack ^ 1), push) : 0;
	while (push--)
		ps_pop(ps, (uint8_t)(stack ^ 1));
}
