/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 00:14:25 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/24 00:22:16 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*new;

	if (lst == NULL)
		return (NULL);
	if ((new = (t_list *)malloc(sizeof(new))) == NULL)
		return (NULL);
	temp = lst;
	new = f(temp);
	if (lst->next != NULL)
		new->next = ft_lstmap(lst->next, f);
	return (new);
}
