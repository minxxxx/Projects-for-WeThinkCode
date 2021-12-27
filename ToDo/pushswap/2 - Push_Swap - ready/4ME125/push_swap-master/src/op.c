/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:16:00 by alucas-           #+#    #+#             */
/*   Updated: 2018/03/12 18:16:02 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

inline void	ps_swap(struct s_ps *ps, uint8_t stack)
{
	t_lst	*s;
	char	*op;

	s = ps->stacks + stack;
	if (!s->len)
		return ;
	ft_nodenswp(s->head);
	if (ps->options & OPT_OPTI)
		*(uint8_t *)ft_vecpush(&ps->ops) = OP_S + stack;
	if ((ps->options & OPT_OPLOG) || (ps->options & OPT_STEP) ||
		(ps->options & OPT_VERB))
	{
		op = ps_opstr(OP_S + stack);
		write(ps->output, op, ft_strlen(op));
		if (!(ps->options & OPT_OPLOG))
			ps_dump(ps, STACK_BOTH);
	}
	if (ps->options & OPT_STEP)
		read(STDIN_FILENO, NULL, 1);
}

inline void	ps_pop(struct s_ps *ps, uint8_t stack)
{
	t_lst	*s;
	t_lst	*o;
	t_node	*node;
	char	*op;

	s = ps->stacks + stack;
	o = ps->stacks + (stack ^ 1);
	if (!s->len)
		return ;
	node = s->head;
	--s->len;
	ft_nodeulink(node, node->prev, node->next);
	ft_lstusht(o, node);
	if (ps->options & OPT_OPTI)
		*(uint8_t *)ft_vecpush(&ps->ops) = OP_P + (stack ^ 1);
	if ((ps->options & OPT_OPLOG) || (ps->options & OPT_STEP) ||
		(ps->options & OPT_VERB))
	{
		op = ps_opstr(OP_P + (stack ^ 1));
		write(ps->output, op, ft_strlen(op));
		if (!(ps->options & OPT_OPLOG))
			ps_dump(ps, STACK_BOTH);
	}
	if (ps->options & OPT_STEP)
		read(STDIN_FILENO, NULL, 1);
}

inline void	ps_rotate(struct s_ps *ps, uint8_t stack)
{
	t_lst	*s;
	char	*op;

	s = ps->stacks + stack;
	if (!s->len)
		return ;
	ft_nodenswp((t_node *)s);
	if (ps->options & OPT_OPTI)
		*(uint8_t *)ft_vecpush(&ps->ops) = OP_R + stack;
	if ((ps->options & OPT_OPLOG) || (ps->options & OPT_STEP) ||
		(ps->options & OPT_VERB))
	{
		op = ps_opstr(OP_R + stack);
		write(ps->output, op, ft_strlen(op));
		if (!(ps->options & OPT_OPLOG))
			ps_dump(ps, STACK_BOTH);
	}
	if (ps->options & OPT_STEP)
		read(STDIN_FILENO, NULL, 1);
}

inline void	ps_rrotate(struct s_ps *ps, uint8_t stack)
{
	t_lst	*s;
	char	*op;

	s = ps->stacks + stack;
	if (!s->len)
		return ;
	ft_nodenswp(s->tail);
	if (ps->options & OPT_OPTI)
		*(uint8_t *)ft_vecpush(&ps->ops) = OP_RR + stack;
	if ((ps->options & OPT_OPLOG) || (ps->options & OPT_STEP) ||
		(ps->options & OPT_VERB))
	{
		op = ps_opstr(OP_RR + stack);
		write(ps->output, op, ft_strlen(op));
		if (!(ps->options & OPT_OPLOG))
			ps_dump(ps, STACK_BOTH);
	}
	if (ps->options & OPT_STEP)
		read(STDIN_FILENO, NULL, 1);
}

inline char	*ps_opstr(uint8_t op)
{
	static char	*ops[] = {
		[OP_S + STACK_A] = "sa\n",
		[OP_S + STACK_B] = "sb\n",
		[OP_S + STACK_BOTH] = "ss\n",
		[OP_P + STACK_A] = "pa\n",
		[OP_P + STACK_B] = "pb\n",
		[OP_R + STACK_A] = "ra\n",
		[OP_R + STACK_B] = "rb\n",
		[OP_R + STACK_BOTH] = "rr\n",
		[OP_RR + STACK_A] = "rra\n",
		[OP_RR + STACK_B] = "rrb\n",
		[OP_RR + STACK_BOTH] = "rrr\n"
	};

	if (op < 0 || op > OP_RR + STACK_BOTH)
	{
		errno = EINVAL;
		return (NULL);
	}
	return (ops[op]);
}
