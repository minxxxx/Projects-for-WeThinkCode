/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 14:07:48 by cfavero           #+#    #+#             */
/*   Updated: 2018/04/24 12:12:04 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_s_b(t_lst **a, t_lst **b)
{
	(void)a;
	if (!(*b && (*b)->next))
		return (1);
	(*b) = (*b)->next;
	if ((*b)->next != (*b)->prev)
	{
		(*b)->prev->next = (*b)->next;
		(*b)->next = (*b)->prev;
		(*b)->prev = (*b)->prev->prev;
		(*b)->next->next->prev = (*b)->next;
		(*b)->next->prev = (*b);
		(*b)->prev->next = (*b);
	}
	return (1);
}

int		ft_s_a(t_lst **a, t_lst **b)
{
	ft_s_b(b, a);
	return (1);
}

int		ft_s_s(t_lst **a, t_lst **b)
{
	ft_s_b(a, b);
	ft_s_a(a, b);
	return (1);
}
