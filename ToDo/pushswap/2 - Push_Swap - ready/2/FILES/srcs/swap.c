/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:15:24 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/26 17:15:25 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_pushswap *data, int final)
{
	int		temp;

	if (data->length_a > 1)
	{
		temp = data->pile_a[data->length_a - 1];
		data->pile_a[data->length_a - 1] = data->pile_a[data->length_a - 2];
		data->pile_a[data->length_a - 2] = temp;
		if (data->pos_smallest_a == data->length_a - 1)
			data->pos_smallest_a = data->length_a - 2;
		else if (data->pos_smallest_a == data->length_a - 2)
			data->pos_smallest_a = data->length_a - 1;
		data->nb_of_moves++;
		print_move_with_options(data, 7, final);
	}
}

void	swap_b(t_pushswap *data, int final)
{
	int		temp;

	if (data->length_b > 1)
	{
		temp = data->pile_b[data->length_b - 1];
		data->pile_b[data->length_b - 1] = data->pile_b[data->length_b - 2];
		data->pile_b[data->length_b - 2] = temp;
		data->nb_of_moves++;
		print_move_with_options(data, 8, final);
	}
}

void	swap_ab(t_pushswap *data, int final)
{
	data->nb_of_moves--;
	swap_a(data, final);
	swap_b(data, final);
}
