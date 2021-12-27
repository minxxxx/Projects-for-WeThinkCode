/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <cfavero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:04:47 by cfavero           #+#    #+#             */
/*   Updated: 2018/05/07 19:36:15 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_p_b(t_lst **a, t_lst **b)
{
	t_lst	*tmp;

	if (!(*a))
		return (1);
	tmp = *a;
	if ((*a)->next != (*a)->prev)
	{
		(*a)->prev->next = (*a)->next;
		(*a)->next->prev = (*a)->prev;
		(*a) = (*a)->next;
	}
	else if ((*a)->next == NULL)
		(*a) = NULL;
	else
	{
		(*a) = (*a)->next;
		(*a)->next = NULL;
		(*a)->prev = NULL;
	}
	tmp->next = !(*b) ? NULL : (*b);
	tmp->prev = NULL;
	ft_create_list(b, tmp);
	ft_rr_b(a, b);
	return (1);
}

int		ft_p_a(t_lst **a, t_lst **b)
{
	ft_p_b(b, a);
	return (1);
}
