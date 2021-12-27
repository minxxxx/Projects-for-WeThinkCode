/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:43:16 by fkoehler          #+#    #+#             */
/*   Updated: 2015/12/08 15:39:28 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr1;
	t_list	*ptr2;

	ptr1 = *alst;
	while (ptr1->next != NULL)
	{
		ptr2 = ptr1->next;
		del(ptr1->content, ptr1->content_size);
		free(ptr1);
		ptr1 = ptr2;
	}
	del(ptr1->content, ptr1->content_size);
	free(ptr1);
	*alst = NULL;
}
