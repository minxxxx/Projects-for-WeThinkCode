/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:14:55 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/26 17:36:11 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_pushswap *data, int final)
{
	int		*new_pile_a;

	if (data->length_b > 0)
	{
		new_pile_a = (int *)ft_memalloc(sizeof(int) * (data->length_a + 1));
		ft_memcpy(new_pile_a, data->pile_a, sizeof(int) * data->length_a);
		ft_memdel((void **)&(data->pile_a));
		new_pile_a[data->length_a] = data->pile_b[data->length_b - 1];
		data->pile_a = new_pile_a;
		data->length_a += 1;
		data->length_b -= 1;
		if (data->pile_a[data->length_a - 1] <= data->smallest_a)
		{
			data->smallest_a = data->pile_a[data->length_a - 1];
			data->pos_smallest_a = data->length_a - 1;
		}
		data->nb_of_moves++;
		print_move_with_options(data, 1, final);
	}
}

void	get_smallest_a(t_pushswap *data)
{
	int		i;

	i = 0;
	while (i < data->length_a)
	{
		if (data->pile_a[i] <= data->smallest_a)
		{
			data->smallest_a = data->pile_a[i];
			data->pos_smallest_a = i;
		}
		i++;
	}
}

void	push_b(t_pushswap *data, int final)
{
	int		*new_pile_b;

	if (data->length_a > 0)
	{
		new_pile_b = (int *)ft_memalloc(sizeof(int) * (data->length_b + 1));
		ft_memcpy(new_pile_b, data->pile_b, sizeof(int) * data->length_b);
		ft_memdel((void **)&(data->pile_b));
		new_pile_b[data->length_b] = data->pile_a[data->length_a - 1];
		data->pile_b = new_pile_b;
		data->length_b += 1;
		data->length_a -= 1;
		if (data->pile_b[data->length_b - 1] == data->smallest_a)
		{
			data->smallest_a = data->pile_a[0];
			data->pos_smallest_a = 0;
			get_smallest_a(data);
		}
		data->nb_of_moves++;
		print_move_with_options(data, 2, final);
	}
}
