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

static void		tinysort(t_ps *ps, uint8_t stack, uint32_t n)
{
	t_psnode	*head;
	int64_t		first;
	int64_t		second;

	if (n != 2)
		return ;
	if (!(head = ps_head(ps, stack)))
		return ;
	first = (int64_t)head->val * ps->orders[stack];
	second = (int64_t)head->next->val * ps->orders[stack];
	if (first > second)
		ps_swap(ps, stack);
}

static void		minirelsort(t_ps *ps, uint8_t stack)
{
	t_psnode	*head;
	int64_t		first;
	int64_t		second;
	int64_t		third;

	if (!(head = ps_head(ps, stack)))
		return ;
	first = (int64_t)head->val * ps->orders[stack];
	second = (int64_t)head->next->val * ps->orders[stack];
	third = (int64_t)head->next->next->val * ps->orders[stack];
	if (first > second && second < third && first < third)
		ps_swap(ps, stack);
	else if (first < second && third < first)
		ps_rrotate(ps, stack);
	else if (first > second && second < third)
		ps_rotate(ps, stack);
	else if (first > second && second > third)
		ps_swap(ps, stack);
	else if (first > second && second < third)
		ps_rrotate(ps, stack);
	else if (first < second && second > third && first < third)
		ps_rrotate(ps, stack);
	else
		return ;
	minirelsort(ps, stack);
}

void			ps_minisort(t_ps *ps, uint8_t stack, uint32_t n)
{
	t_psnode	*head;
	int64_t		second;
	int64_t		third;

	if (n != 3)
		return (tinysort(ps, stack, n));
	if (ps->stacks[stack].len == 3)
		return (minirelsort(ps, stack));
	tinysort(ps, stack, 2);
	if (!(head = ps_head(ps, stack)))
		return ;
	second = head->next->val * ps->orders[stack];
	third = head->next->next->val * ps->orders[stack];
	if (second > third)
	{
		ps_rotate(ps, stack);
		ps_swap(ps, stack);
		ps_rrotate(ps, stack);
	}
	tinysort(ps, stack, 2);
}

void			ps_sort(t_ps *ps, uint8_t stack, uint32_t n)
{
	if (n <= 3)
		return (ps_minisort(ps, stack, n));
	else if (ps->stacks[stack].len <= 20)
		return (ps_selectsort(ps, stack));
	return (ps_quicksort(ps, stack, n));
}
