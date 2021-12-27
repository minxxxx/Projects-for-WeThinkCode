/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:15:06 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/26 17:15:08 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_pushswap *data, int final)
{
	int		last;
	int		i;

	if (data->length_a > 1)
	{
		last = data->pile_a[data->length_a - 1];
		i = data->length_a - 1;
		while (i > 0)
		{
			data->pile_a[i] = data->pile_a[i - 1];
			i--;
		}
		data->pile_a[0] = last;
		data->pos_smallest_a += 1;
		if (data->pos_smallest_a == data->length_a)
			data->pos_smallest_a = 0;
		data->nb_of_moves++;
		print_move_with_options(data, 3, final);
	}
}

void	reverse_rotate_b(t_pushswap *data, int final)
{
	int		last;
	int		i;

	if (data->length_b > 1)
	{
		last = data->pile_b[data->length_b - 1];
		i = data->length_b - 1;
		while (i > 0)
		{
			data->pile_b[i] = data->pile_b[i - 1];
			i--;
		}
		data->pile_b[0] = last;
		data->nb_of_moves++;
		print_move_with_options(data, 4, final);
	}
}

void	reverse_rotate_ab(t_pushswap *data, int final)
{
	data->nb_of_moves--;
	reverse_rotate_a(data, final);
	reverse_rotate_b(data, final);
}
