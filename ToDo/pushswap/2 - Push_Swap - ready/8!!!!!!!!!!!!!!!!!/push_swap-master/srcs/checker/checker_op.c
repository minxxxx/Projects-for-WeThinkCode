/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 13:53:56 by ljoly             #+#    #+#             */
/*   Updated: 2017/07/06 16:22:15 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		reverse_rotate(t_stack *e, int *st, int len)
{
	int			i;
	int			j;

	if (len > 1)
	{
		i = st[len - 1];
		j = len;
		while (--j > 0)
			st[j] = st[j - 1];
		st[j] = i;
	}
	e->op_ok = 1;
}

static void		rotate(t_stack *e, int *st, int len)
{
	int			i;
	int			j;

	if (len > 1)
	{
		i = st[0];
		j = -1;
		while (++j + 1 < len)
			st[j] = st[j + 1];
		st[j] = i;
	}
	e->op_ok = 1;
}

static void		push(int *st1, int *st2, int *len1, int *len2)
{
	int			i;
	int			j;

	if (*len2 > 0)
	{
		i = st2[0];
		j = -1;
		while (++j + 1 < *len2)
			st2[j] = st2[j + 1];
		*len2 -= 1;
		j = *len1 + 1;
		while (--j > 0)
			st1[j] = st1[j - 1];
		st1[0] = i;
		*len1 += 1;
	}
}

static void		swap(t_stack *e, int *tab, int len)
{
	int			i;

	if (len > 1)
	{
		i = tab[0];
		tab[0] = tab[1];
		tab[1] = i;
	}
	e->op_ok = 1;
}

int				get_operations(char *line, t_stack *e)
{
	if (ft_strequ(line, "sa") || ft_strequ(line, "ss"))
		swap(e, e->stack_a, e->len_a);
	if (ft_strequ(line, "sb") || ft_strequ(line, "ss"))
		swap(e, e->stack_b, e->len_b);
	else if (ft_strequ(line, "pa") && (e->op_ok = 1))
		push(e->stack_a, e->stack_b, &e->len_a, &e->len_b);
	else if (ft_strequ(line, "pb") && (e->op_ok = 1))
		push(e->stack_b, e->stack_a, &e->len_b, &e->len_a);
	else if (ft_strequ(line, "ra") || ft_strequ(line, "rr"))
		rotate(e, e->stack_a, e->len_a);
	if (ft_strequ(line, "rb") || ft_strequ(line, "rr"))
		rotate(e, e->stack_b, e->len_b);
	else if (ft_strequ(line, "rra") || ft_strequ(line, "rrr"))
		reverse_rotate(e, e->stack_a, e->len_a);
	if (ft_strequ(line, "rrb") || ft_strequ(line, "rrr"))
		reverse_rotate(e, e->stack_b, e->len_b);
	if (!e->op_ok)
		return (0);
	return (1);
}
