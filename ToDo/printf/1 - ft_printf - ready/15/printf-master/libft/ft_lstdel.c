/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:16:52 by fkuhn             #+#    #+#             */
/*   Updated: 2018/11/28 15:13:00 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alist, void (*del)(void *, size_t))
{
	t_list	*next;
	t_list	*curr;

	if (alist && del)
	{
		curr = (*alist);
		next = (*alist)->next;
		while (curr)
		{
			next = curr->next;
			del(curr->content, curr->content_size);
			free(curr);
			curr = next;
		}
		*alist = NULL;
	}
}
