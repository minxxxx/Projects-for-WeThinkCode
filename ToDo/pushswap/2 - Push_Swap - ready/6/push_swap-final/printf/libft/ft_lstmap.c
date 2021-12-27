/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:38:52 by cfavero           #+#    #+#             */
/*   Updated: 2017/12/01 14:12:01 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*tmp;
	t_list	*start;

	tmp = f(lst);
	fresh = ft_lstnew(tmp->content, tmp->content_size);
	start = fresh;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		fresh->next = ft_lstnew(tmp->content, tmp->content_size);
		fresh = fresh->next;
		lst = lst->next;
	}
	return (start);
}
