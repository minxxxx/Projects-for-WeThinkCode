/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <cfavero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 15:09:46 by cfavero           #+#    #+#             */
/*   Updated: 2018/05/10 15:43:17 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_random_3(t_all *data, int opt, int ch)
{
	long		i;
	static int	ct = 0;

	i = 1000000000 / 2;
	if (opt & C && ch == 0)
	{
		while (i)
			i--;
		ft_printf("0\033[H\033[2J");
		ft_print_2stack(data->lst_a, data->lst_b);
	}
	else if (opt & V && !(opt & C))
	{
		if (ch == 0)
			ct++;
		else
			ft_printf("%d\n", ct);
	}
}

int			ft_random_2(t_all *data, int ch)
{
	if (data)
	{
		if (data->lst_a && data->lst_a->next)
			ft_lstclean(&data->lst_a);
		else if (data->lst_a)
			free(data->lst_a);
		if (data->lst_b && data->lst_b->next)
			ft_lstclean(&data->lst_b);
		else if (data->lst_b)
			free(data->lst_b);
		free(data);
	}
	return (ch);
}

int			ft_random_4(int *arr, int ch)
{
	free(arr);
	return (ch);
}

static void	ft_bubble_algo_pt2(t_all *data, int round)
{
	while (round--)
	{
		RRA;
		data->moves += ft_printf("%s", "rra\n") / 4;
	}
}

void		ft_bubble_algo(t_all *data)
{
	int		len;
	int		round;

	round = 0;
	len = ft_lstlen(data->lst_a);
	while (ft_are_sorted_a_val(data->lst_a) == 1)
	{
		if (AA > AB && AA != len - 1)
		{
			SA;
			data->moves += ft_printf("%s", "sa\n") / 3;
			if (ft_are_sorted_a_val(data->lst_a) == 0)
				break ;
			if (round < len / 2)
				ft_bubble_algo_pt2(data, round);
			round = 0;
		}
		else
		{
			round++;
			RA;
			data->moves += ft_printf("%s", "ra\n") / 3;
		}
	}
}
