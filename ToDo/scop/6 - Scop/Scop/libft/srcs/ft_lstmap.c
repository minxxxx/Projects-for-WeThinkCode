/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 08:44:27 by ggroener          #+#    #+#             */
/*   Updated: 2016/05/14 08:05:01 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*new_list_item;

	if (lst)
	{
		new_list = f(lst);
		new_list_item = new_list;
		lst = lst->next;
		while (lst)
		{
			new_list_item->next = f(lst);
			new_list_item = new_list_item->next;
			lst = lst->next;
		}
		return (new_list);
	}
	return (NULL);
}
