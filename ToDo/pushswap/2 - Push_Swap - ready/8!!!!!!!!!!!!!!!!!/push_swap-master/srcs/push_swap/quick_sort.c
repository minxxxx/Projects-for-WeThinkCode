/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:25:08 by ljoly             #+#    #+#             */
/*   Updated: 2017/07/06 18:04:01 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		add_med(int **tab_med, int size, int val)
{
	int			i;
	int			*tab;

	tab = *tab_med;
	i = 0;
	while (i < size)
	{
		if (tab[i] == INT_MIN)
		{
			tab[i] = val;
			return ;
		}
		i++;
	}
}

static void		check_b(t_stack *e)
{
	while (is_sorted(e->stack_a, e->len_a, 0, 1) &&
			!is_sorted(e->stack_b, e->len_b, 0, 0))
	{
		if (e->len_b > 1 && e->stack_b[1] == get_max(e->stack_b, e->len_b))
			proceed_op(e, SB);
		if (is_sorted(e->stack_b, e->len_b, 0, 0))
			break ;
		e->med = get_next_med(e, e->stack_b, e->len_b);
		e->dist = get_dist_to_med(e->stack_b, e->len_b, e->med);
		if (e->med != INT_MIN && e->dist > 2 &&
				!is_sorted(e->stack_b, e->dist, 0, 2))
		{
			add_med(&e->tab_med, e->param, get_med(e->stack_b, e->dist));
			e->med = get_next_med(e, e->stack_b, e->dist);
			e->tab_med_i++;
		}
		else if (e->med == INT_MIN)
		{
			add_med(&e->tab_med, e->param, get_med(e->stack_b, e->len_b));
			e->med = e->tab_med[e->tab_med_i];
			e->dist = e->len_b;
			e->tab_med_i++;
		}
		split_b(e, e->stack_b);
	}
}

static void		check_a(t_stack *e)
{
	while (!is_sorted(e->stack_a, e->len_a, 0, 1))
	{
		if (e->len_a > 1 && e->stack_a[1] == get_min(e->stack_a, e->len_a))
			proceed_op(e, SA);
		if (is_sorted(e->stack_a, e->len_a, 0, 1))
			break ;
		e->med = get_next_med(e, e->stack_a, e->len_a);
		e->dist = get_dist_to_med(e->stack_a, e->len_a, e->med);
		if (e->med != INT_MIN && e->dist > 2 &&
				!is_sorted(e->stack_a, e->dist, 0, 1))
		{
			add_med(&e->tab_med, e->param, get_med(e->stack_a, e->dist));
			e->med = get_next_med(e, e->stack_a, e->dist);
			e->tab_med_i++;
		}
		else if (e->med == INT_MIN)
		{
			add_med(&e->tab_med, e->param, get_med(e->stack_a, e->len_a));
			e->med = e->tab_med[e->tab_med_i];
			e->dist = e->len_a;
			e->tab_med_i++;
		}
		split_a(e, e->stack_a);
	}
}

void			quick_sort(t_stack *e)
{
	int			i;

	e->tab_med = (int*)ft_memalloc(sizeof(int) * e->param);
	i = -1;
	while (++i < e->param)
		e->tab_med[i] = INT_MIN;
	e->tab_med_i = 0;
	e->first_round = 0;
	while (!is_sorted(e->stack_a, e->len_a, 0, 1) ||
			!is_sorted(e->stack_b, e->len_b, 0, 0))
	{
		check_a(e);
		e->first_round = 1;
		check_b(e);
	}
	while (e->len_b)
		proceed_op(e, PA);
}
