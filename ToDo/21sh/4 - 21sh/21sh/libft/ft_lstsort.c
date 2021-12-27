/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 18:47:27 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/24 19:22:14 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sorted_lst(t_list **lst)
{
	if (*lst != NULL)
	{
		if ((*lst)->next != NULL)
		{
			if (ft_memcmp((*lst)->content, (*lst)->next->content, (*lst)->content_size) > 0)
				return (1);
		}
		return (ft_sorted_lst(&(*lst)->next));
	}
	return (0);
}

void	ft_sort_lst(t_list **lst)
{
	t_list	*t;

	if (*lst != NULL)
	{
		if ((*lst)->next != NULL)
		{
			if (ft_memcmp((*lst)->content, (*lst)->next->content, (*lst)->content_size) > 0)
			{
				t = (*lst)->next;
				(*lst)->next = (*lst)->next->next;
				t->next = *lst;
				*lst = t;
			}
		}
		ft_sort_lst(&(*lst)->next);
	}
}

void	ft_lstsort(t_list **lst)
{
	while (ft_sorted_lst(&(*lst)) == 1)
	{
		ft_sort_lst(&(*lst));
	}
}
