/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:26:14 by opodolia          #+#    #+#             */
/*   Updated: 2016/12/06 17:57:42 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_clean_res(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		ft_memdel((void **)lst);
		lst = tmp;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*res;

	res = 0;
	if (lst)
	{
		list = (*f)(ft_lstnew(lst->content, lst->content_size));
		res = list;
		while (lst->next)
		{
			lst = lst->next;
			list->next = (*f)(ft_lstnew(lst->content, lst->content_size));
			if (list->next)
				list = list->next;
			else
			{
				ft_clean_res(res);
				return (0);
			}
		}
	}
	return (res);
}
