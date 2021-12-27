/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:57:46 by wide-aze          #+#    #+#             */
/*   Updated: 2014/11/11 17:59:48 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*link;
	t_list	*f_app;

	link = NULL;
	f_app = NULL;
	if (lst && f)
	{
		link = ft_lstnew((f(lst))->content, (f(lst))->content_size);
		if (!link)
			return (NULL);
		f_app = link;
		lst = lst->next;
		while (lst)
		{
			f_app->next = ft_lstnew((f(lst))->content, (f(lst))->content_size);
			if (!(f_app->next))
				return (NULL);
			f_app = f_app->next;
			lst = lst->next;
		}
		return (link);
	}
	return (NULL);
}
