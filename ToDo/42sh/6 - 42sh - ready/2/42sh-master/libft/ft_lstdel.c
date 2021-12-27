/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:14:21 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:14:24 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*next;

	if (alst && del)
	{
		current = *alst;
		while (current)
		{
			next = current->next;
			del(current->content, current->content_size);
			free(current);
			current = next;
		}
	}
	*alst = NULL;
}
