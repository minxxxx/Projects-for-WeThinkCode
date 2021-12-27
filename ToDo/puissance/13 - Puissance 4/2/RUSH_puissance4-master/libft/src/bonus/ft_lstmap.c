/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 12:43:39 by thou              #+#    #+#             */
/*   Updated: 2016/11/20 13:48:28 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*dst;
	t_list	*tmp2;

	if (!lst)
		return (NULL);
	tmp = lst;
	dst = ft_lstnew(lst->content, lst->content_size);
	if (!dst)
		return (NULL);
	dst = f(lst);
	tmp2 = dst;
	while (tmp->next)
	{
		tmp2->next = f(tmp->next);
		tmp2 = tmp2->next;
		tmp = tmp->next;
	}
	return (dst);
}
