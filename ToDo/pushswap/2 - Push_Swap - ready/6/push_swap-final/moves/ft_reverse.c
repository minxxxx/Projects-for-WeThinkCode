/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:04:47 by cfavero           #+#    #+#             */
/*   Updated: 2018/04/24 12:11:42 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_rr_b(t_lst **a, t_lst **b)
{
	(void)a;
	if (!(*b && (*b)->next))
		return (1);
	(*b) = (*b)->prev;
	return (1);
}

int		ft_rr_a(t_lst **a, t_lst **b)
{
	ft_rr_b(b, a);
	return (1);
}

int		ft_rr_r(t_lst **a, t_lst **b)
{
	ft_rr_b(a, b);
	ft_rr_a(a, b);
	return (1);
}
