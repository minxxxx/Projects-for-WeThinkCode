/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:56:36 by fkoehler          #+#    #+#             */
/*   Updated: 2015/12/08 15:40:04 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ptr;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	if (!new)
		return (NULL);
	lst = lst->next;
	ptr = new;
	while (lst != NULL)
	{
		ptr->next = f(lst);
		if (!ptr->next)
			return (NULL);
		ptr = ptr->next;
		lst = lst->next;
	}
	ptr->next = NULL;
	return (new);
}
