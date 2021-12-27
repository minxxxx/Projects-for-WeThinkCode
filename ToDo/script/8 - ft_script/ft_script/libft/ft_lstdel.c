/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 11:48:51 by wide-aze          #+#    #+#             */
/*   Updated: 2015/08/13 22:20:39 by dw31             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*next_list;

	if (alst && del)
	{
		list = *alst;
		next_list = list->next;
		while (next_list)
		{
			next_list = list->next;
			del(list->content, list->content_size);
			free(list);
			list = next_list;
		}
		if (list != NULL)
		{
			del(list->content, list->content_size);
			free(list);
		}
		*alst = NULL;
	}
}
