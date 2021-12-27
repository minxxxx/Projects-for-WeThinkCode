/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:18:44 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/24 16:18:45 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*begin_lst;
	t_list		*fw_lst;

	if (!lst || !f)
		return (NULL);
	fw_lst = f(lst);
	begin_lst = fw_lst;
	if (begin_lst == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		fw_lst->next = f(lst);
		if (fw_lst->next == NULL)
			return (NULL);
		fw_lst = fw_lst->next;
	}
	return (begin_lst);
}
