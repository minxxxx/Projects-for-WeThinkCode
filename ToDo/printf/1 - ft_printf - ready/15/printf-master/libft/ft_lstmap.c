/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:47:25 by fkuhn             #+#    #+#             */
/*   Updated: 2018/11/28 16:38:53 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*tmp;
	t_list	*next;
	t_list	*curr;

	if (!lst || !f)
		return (NULL);
	newlst = f(lst);
	if (!newlst)
		return (NULL);
	tmp = newlst;
	curr = lst->next;
	while (curr)
	{
		next = curr->next;
		newlst->next = f(curr);
		if (!newlst->next)
			return (NULL);
		curr = next;
		newlst = newlst->next;
	}
	return (tmp);
}
