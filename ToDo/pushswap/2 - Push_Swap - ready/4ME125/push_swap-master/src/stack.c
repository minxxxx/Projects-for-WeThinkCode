/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:16:00 by alucas-           #+#    #+#             */
/*   Updated: 2018/03/12 18:16:02 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

inline t_psnode		*ps_head(t_ps *ps, uint8_t stack)
{
	t_lst *s;

	s = ps->stacks + stack;
	if (s->len)
		return ((t_psnode *)s->head);
	return (NULL);
}

inline void			ps_dump(t_ps *ps, uint8_t stack)
{
	t_psnode *node;

	if (stack == STACK_BOTH)
	{
		ps_dump(ps, STACK_A);
		return (ps_dump(ps, STACK_B));
	}
	if (!(node = ps_head(ps, stack)))
		return ;
	ft_dprintf(2, "%c[", stack ? 'B' : 'A');
	while (node != (t_psnode *)(ps->stacks + stack))
	{
		ft_dprintf(2, "%d", node->val);
		node = node->next;
		if (node != (t_psnode *)(ps->stacks + stack))
			ft_dprintf(2, " ");
	}
	ft_dprintf(2, "]\n");
}

static inline int	compare(t_nval const *a, t_nval const *b)
{
	return ((a->val > b->val) - (a->val < b->val));
}

void				ps_norm(t_ps *ps, uint8_t stack)
{
	t_psnode	*node;
	t_nval		vals[(ps->stacks + stack)->len];
	t_nval		*it;

	it = vals;
	node = ps_head(ps, stack);
	while (node != (t_psnode *)(ps->stacks + stack))
	{
		*it = (t_nval){node->val, (uint32_t)(it - vals)};
		++it;
		node = node->next;
	}
	ft_shellsort(vals, it - vals, sizeof(t_nval), (t_ncmp *)compare);
	while (--it >= vals)
	{
		node = ps->nodes;
		while (it->idx--)
			++node;
		node->val = (uint32_t)(it - vals);
	}
}

int					ps_issort(t_ps *ps, uint8_t stack, int64_t n)
{
	t_psnode *node;
	t_psnode *next;

	if (n < 0)
		n = (int)ps->stacks[stack].len;
	if (!(node = ps_head(ps, stack)))
		return (1);
	while (n-- && node != (t_psnode *)ps->stacks[stack].tail)
	{
		next = node->next;
		if (ps->orders[stack] == 1 && node->val > next->val)
			return (0);
		if (ps->orders[stack] == -1 && node->val < next->val)
			return (0);
		node = next;
	}
	return (1);
}
