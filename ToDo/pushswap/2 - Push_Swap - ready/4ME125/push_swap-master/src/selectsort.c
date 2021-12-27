/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:16:00 by alucas-           #+#    #+#             */
/*   Updated: 2018/03/12 18:16:02 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void		ps_moveto(t_ps *ps, uint8_t stack, uint32_t idx)
{
	if (idx == 1)
		ps_swap(ps, stack);
	else if (idx > 1)
	{
		if (idx <= ps->stacks[stack].len / 2)
		{
			while (idx--)
				ps_rotate(ps, stack);
		}
		else
		{
			while (ps->stacks[stack].len - idx)
			{
				ps_rrotate(ps, stack);
				++idx;
			}
		}
	}
}

static void		selectsorta(t_ps *ps, uint8_t stack)
{
	t_psnode	*node;
	int64_t		min;
	uint32_t	idx[2];

	if (ps->stacks[stack].len <= 3)
		return (ps_minisort(ps, stack, (uint32_t)ps->stacks[stack].len));
	node = ps_head(ps, stack);
	min = UINT32_MAX;
	ft_bzero(idx, 2 * sizeof(uint32_t));
	while (node != (t_psnode *)(ps->stacks + stack))
	{
		if (node->val < min)
		{
			min = node->val;
			idx[0] = idx[1];
		}
		++idx[1];
		node = node->next;
	}
	ps_moveto(ps, stack, idx[0]);
	ps_pop(ps, stack);
	selectsorta(ps, stack);
	ps_pop(ps, (uint8_t)(stack ^ 1));
}

void			ps_selectsort(t_ps *ps, uint8_t s)
{
	t_psnode	*node;
	int64_t		max;
	uint32_t	idx[2];

	if (s == STACK_A)
		return (selectsorta(ps, s));
	if (!ps->stacks[s].len)
		return ;
	node = ps_head(ps, s);
	max = 0;
	ft_bzero(idx, 2 * sizeof(uint32_t));
	while (node != (t_psnode *)(ps->stacks + s))
	{
		if (node->val > max)
		{
			max = node->val;
			idx[0] = idx[1];
		}
		++idx[1];
		node = node->next;
	}
	ps_moveto(ps, s, idx[0]);
	ps_pop(ps, s);
	ps_selectsort(ps, s);
}
