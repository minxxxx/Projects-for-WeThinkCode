/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:44:18 by telain            #+#    #+#             */
/*   Updated: 2015/12/12 13:44:08 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*start;
	t_list	*tmp;

	tmp = f(lst);
	new = ft_lstnew(tmp->content, tmp->content_size);
	start = new;
	while (lst->next)
	{
		tmp = f(lst->next);
		new->next = ft_lstnew(tmp->content, tmp->content_size);
		new = new->next;
		lst = lst->next;
	}
	return (start);
}
