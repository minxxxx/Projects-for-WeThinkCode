/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_med_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:30:23 by ljoly             #+#    #+#             */
/*   Updated: 2017/07/06 16:25:11 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				get_dist_to_med(int *st, int size, int next_med)
{
	int			i;

	i = 0;
	while (i < size && st[i] != next_med)
		i++;
	if (i == size)
		return (0);
	return (i);
}

int				get_next_med(t_stack *e, int *st, int size)
{
	int			i;
	int			j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < e->param && e->tab_med[j] != INT_MIN)
		{
			if (st[i] == e->tab_med[j])
				return (e->tab_med[j]);
			j++;
		}
		i++;
	}
	return (INT_MIN);
}

int				get_max(int *st, int len)
{
	int			i;
	int			j;
	int			max;

	max = INT_MIN;
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (st[j] > max)
				max = st[j];
		}
	}
	return (max);
}

int				get_min(int *st, int len)
{
	int			i;
	int			j;
	int			min;

	min = INT_MAX;
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (st[j] < min)
				min = st[j];
		}
	}
	return (min);
}

int				get_med(int *st, int len)
{
	int			i;
	int			j;
	int			dist;
	int			med;

	i = -1;
	med = INT_MIN;
	while (++i < len)
	{
		dist = 0;
		j = -1;
		while (++j < len)
		{
			if (st[j] > st[i])
				dist++;
		}
		if (dist == (len % 2 == 0 ? (len / 2) - 1 : len / 2))
		{
			med = st[i];
			break ;
		}
	}
	return (med);
}
