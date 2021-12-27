/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 15:39:57 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/27 15:44:33 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		put_smallest_last(t_pushswap *data)
{
	int		i;

	i = 0;
	if (data->pos_smallest_a < data->length_a / 2)
	{
		while (data->pos_smallest_a != data->length_a - 1)
			rotate_a(data, 0);
	}
	else
	{
		while (data->pos_smallest_a != data->length_a - 1)
			reverse_rotate_a(data, 0);
	}
}

static void		check_swap(t_pushswap *data)
{
	int nb;
	int i;
	int pos;

	i = 0;
	if (data->pile_a[0] != data->smallest_a)
		nb = data->pile_a[0];
	else
		nb = data->pile_a[1];
	while (data->pile_a[i])
	{
		if (data->pile_a[i] > data->smallest_a && data->pile_a[i] <= nb)
		{
			nb = data->pile_a[i];
			pos = i;
		}
		i++;
	}
	if (pos == data->length_a - 1)
		swap_a(data, 0);
}

static void		check_swap_beg(t_pushswap *data)
{
	int		i;

	if (data->length_a == 2 || data->length_a == 3)
		return ;
	i = 3;
	while (i < data->length_a)
	{
		if (data->pile_a[i - 1] < data->pile_a[i]
				|| data->pile_a[i - 1] > data->pile_a[1])
			return ;
		i++;
	}
	rotate_a(data, 0);
	rotate_a(data, 0);
	swap_a(data, 0);
	if (check_pile(data->pile_a, data->length_a))
		return ;
	reverse_rotate_a(data, 0);
	reverse_rotate_a(data, 0);
}

static void		first_pile_check(t_pushswap *data)
{
	if (data->length_a == 3
			&& check_pile_reverse(data->pile_a, data->length_a))
	{
		reverse_rotate_a(data, 0);
		swap_a(data, 0);
	}
	if (data->pile_a[0] < data->pile_a[1])
		check_swap_beg(data);
	if (data->pos_smallest_a == data->length_a - 2)
		check_swap(data);
}

void			sort_pile(t_pushswap *data)
{
	while (42)
	{
		first_pile_check(data);
		put_smallest_last(data);
		if (check_pile(data->pile_a, data->length_a))
		{
			if (data->length_b == 0)
				break ;
			else if (data->length_b == 1)
				push_a(data, 1);
			else
			{
				while (data->length_b > 0)
					push_a(data, 0);
			}
		}
		else
			push_b(data, 0);
	}
}
