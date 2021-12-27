/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:24:32 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/11 15:24:33 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*temp_list;
	t_list	*f_list;

	if (!lst || !f)
		return (NULL);
	f_list = f(lst);
	new_list = ft_lstnew(f_list->content, f_list->content_size);
	if (new_list != NULL)
	{
		temp_list = new_list;
		lst = lst->next;
		while (lst)
		{
			f_list = f(lst);
			temp_list->next = ft_lstnew(f_list->content, f_list->content_size);
			if (temp_list->next == NULL)
				return (NULL);
			temp_list = temp_list->next;
			lst = lst->next;
		}
	}
	return (new_list);
}
