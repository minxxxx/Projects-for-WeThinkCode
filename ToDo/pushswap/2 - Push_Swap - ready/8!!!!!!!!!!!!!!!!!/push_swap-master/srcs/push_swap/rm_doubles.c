/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_doubles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 14:15:51 by ljoly             #+#    #+#             */
/*   Updated: 2017/07/06 17:21:25 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		delete(t_op **op, t_op *tmp, t_op *tmp2)
{
	if (tmp2->prev && tmp->next)
	{
		tmp2->prev->next = tmp->next;
		tmp->next->prev = tmp2->prev;
		free(tmp);
	}
	else if (tmp2->prev)
	{
		tmp2->prev->next = NULL;
		free(tmp);
		*op = tmp2->prev;
	}
	else if (tmp->next)
	{
		tmp->next->prev = NULL;
		free(tmp);
		*op = tmp->next;
	}
}

static void		replace(t_op *tmp, t_op *tmp2, char op)
{
	tmp2->prev = tmp->prev;
	if (tmp->prev)
		tmp->prev->next = tmp2;
	tmp2->op = op;
	free(tmp);
}

static void		doit(t_op **op, t_rm *r, char del)
{
	r->tmp = *op;
	r->doit = 0;
	if (del)
		free(r->tmp2);
}

void			replace_ops(t_op **op)
{
	t_rm		r;

	r.doit = 0;
	if (*op)
	{
		r.tmp = *op;
		while (r.tmp && r.tmp->next)
		{
			r.tmp2 = r.tmp->next;
			if (((r.tmp->op == RA && r.tmp2->op == RB) ||
					(r.tmp->op == RB && r.tmp2->op == RA)) && (r.doit = 1))
				replace(r.tmp, r.tmp2, RR);
			else if (((r.tmp->op == RRA && r.tmp2->op == RRB) ||
					(r.tmp->op == RRB && r.tmp2->op == RRA)) && (r.doit = 1))
				replace(r.tmp, r.tmp2, RRR);
			else if (((r.tmp->op == SA && r.tmp2->op == SB) ||
					(r.tmp->op == SB && r.tmp2->op == SA)) && (r.doit = 1))
				replace(r.tmp, r.tmp2, SS);
			if (r.doit)
				doit(op, &r, 0);
			else
				r.tmp = r.tmp2;
		}
	}
}

void			delete_ops(t_op **op)
{
	t_rm		r;

	r.doit = 0;
	if (*op)
	{
		r.tmp = *op;
		while (r.tmp && r.tmp->prev)
		{
			r.tmp2 = r.tmp->prev;
			if (((r.tmp->op == PA && r.tmp2->op == PB) ||
						(r.tmp->op == PB && r.tmp2->op == PA)) && (r.doit = 1))
				delete(op, r.tmp, r.tmp2);
			else if (((r.tmp->op == RA && r.tmp2->op == RRA) ||
						(r.tmp->op == RRA && r.tmp2->op == RA)) && (r.doit = 1))
				delete(op, r.tmp, r.tmp2);
			else if (((r.tmp->op == RB && r.tmp2->op == RRB) ||
						(r.tmp->op == RRB && r.tmp2->op == RB)) && (r.doit = 1))
				delete(op, r.tmp, r.tmp2);
			if (r.doit)
				doit(op, &r, 1);
			else
				r.tmp = r.tmp2;
		}
		*op = r.tmp;
	}
}
