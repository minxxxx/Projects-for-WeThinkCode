/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 20:38:22 by ljoly             #+#    #+#             */
/*   Updated: 2017/07/06 16:30:11 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			get_st(char op)
{
	int				st;

	st = 0;
	if (op == SA || op == SS || op == PA || op == PB || op == RA || op == RR ||
			op == RRA || op == RRR)
		st += 1;
	if (op == SB || op == SS || op == PA || op == PB || op == RB || op == RR ||
			op == RRB || op == RRR)
		st += 2;
	return (st);
}

static void			display_colors(t_stack *e, char op)
{
	int				i;
	int				st;

	st = get_st(op);
	ft_printf(""BLUE"%s"NC"\n", "STACK A: ");
	if (st == AB || st == A)
		ft_putstr(GREEN);
	i = 0;
	while (i < e->len_a)
	{
		ft_printf("%d\n", e->stack_a[i]);
		i++;
	}
	ft_printf("\n"BLUE"%s"NC"\n", "STACK B: ");
	if (st == AB || st == B)
		ft_putstr(GREEN);
	i = 0;
	while (i < e->len_b)
	{
		ft_printf("%d\n", e->stack_b[i]);
		i++;
	}
	ft_putendl(NC);
}

void				display_stacks(t_stack *e, char c, char op)
{
	int				i;

	i = 0;
	if (c)
	{
		display_colors(e, op);
		return ;
	}
	ft_printf("%s\n", "STACK A: ");
	while (i < e->len_a)
	{
		ft_printf("%d\n", e->stack_a[i]);
		i++;
	}
	i = 0;
	ft_printf("\n%s\n", "STACK B: ");
	while (i < e->len_b)
	{
		ft_printf("%d\n", e->stack_b[i]);
		i++;
	}
	ft_putchar('\n');
}

static void			init_display(t_display *dsp)
{
	dsp->stacks = 0;
	dsp->refresh = 0;
	dsp->colors = 0;
	dsp->algo = 0;
	dsp->is_moves = 0;
	dsp->moves = 0;
	dsp->flags = 0;
}

void				parse_display(char **argv, t_display *dsp)
{
	int				i;

	init_display(dsp);
	i = 1;
	while (argv[i])
	{
		if (ft_strequ(argv[i], "-s"))
			dsp->stacks = 1;
		else if (ft_strequ(argv[i], "-r"))
			dsp->refresh = 1;
		else if (ft_strequ(argv[i], "-c"))
			dsp->colors = 1;
		else if (ft_strequ(argv[i], "-a"))
			dsp->algo = 1;
		else if (ft_strequ(argv[i], "-m"))
			dsp->is_moves = 1;
		i++;
	}
	dsp->flags = dsp->stacks + dsp->refresh + dsp->colors + dsp->algo +
		dsp->is_moves;
}
