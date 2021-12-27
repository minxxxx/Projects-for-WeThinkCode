/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 10:51:30 by dtedgui           #+#    #+#             */
/*   Updated: 2015/12/01 13:12:52 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*link;
	t_list	*tmp;

	tmp = (*f)(lst);
	if (!(new_list = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	lst = lst->next;
	link = new_list;
	while (lst)
	{
		tmp = (*f)(lst);
		link->next = ft_lstnew(tmp->content, tmp->content_size);
		lst = lst->next;
		link = link->next;
	}
	return (new_list);
}
