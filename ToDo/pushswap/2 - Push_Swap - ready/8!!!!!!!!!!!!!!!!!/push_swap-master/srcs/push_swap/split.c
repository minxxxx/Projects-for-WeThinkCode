/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 17:24:32 by ljoly             #+#    #+#             */
/*   Updated: 2017/07/06 18:13:37 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		check_med(t_stack *e, int *st, int a)
{
	if (a)
	{
		if (e->is_med && next_target(st, e->dist, e->med, 1) != INT_MAX
				&& (e->med_pushed = 1) && e->len_b > 1)
			proceed_op(e, RB);
		else if (e->is_med && next_target(st, e->dist, e->med, 2) == INT_MIN)
			e->med_pushed = 1;
		else if (e->med_pushed && next_target(st, e->dist, e->med, 1) ==
				INT_MAX)
			proceed_op(e, RRB);
	}
	else
	{
		if (e->is_med && next_target(st, e->dist, e->med, 3) != INT_MIN
				&& (e->med_pushed = 1) && e->len_a > 1)
			proceed_op(e, RA);
		else if (e->is_med && next_target(st, e->dist, e->med, 2) == INT_MIN)
			e->med_pushed = 1;
		else if (e->med_pushed && next_target(st, e->dist, e->med, 3) ==
				INT_MIN)
			proceed_op(e, RRA);
	}
}

void			split_b(t_stack *e, int *st)
{
	int			op;
	int			back_in_order;

	e->med_pushed = 0;
	back_in_order = 1;
	while (!e->med_pushed || next_target(st, e->dist, e->med, 3) != INT_MIN)
	{
		e->is_med = 0;
		if (st[0] > e->med || (st[0] == e->med &&
					(e->is_med = 1)))
		{
			e->dist--;
			op = PA;
		}
		else
		{
			back_in_order++;
			op = RB;
		}
		proceed_op(e, op);
		check_med(e, e->stack_b, 0);
	}
	while (--back_in_order && !is_sorted(st, e->len_b, 0, 0))
		proceed_op(e, RRB);
}

void			split_a(t_stack *e, int *st)
{
	int			op;
	int			back_in_order;

	e->med_pushed = 0;
	back_in_order = 1;
	while (!e->med_pushed || next_target(st, e->dist, e->med, 1) != INT_MAX)
	{
		e->is_med = 0;
		if (st[0] < e->med || (st[0] == e->med &&
					(e->is_med = 1)))
		{
			e->dist--;
			op = PB;
		}
		else
		{
			back_in_order++;
			op = RA;
		}
		proceed_op(e, op);
		check_med(e, e->stack_a, 1);
	}
	while (e->first_round && --back_in_order && !is_sorted(st, e->len_a, 0, 1))
		proceed_op(e, RRA);
}
