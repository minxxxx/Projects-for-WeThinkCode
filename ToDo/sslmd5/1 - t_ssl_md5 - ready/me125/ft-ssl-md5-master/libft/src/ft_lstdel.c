/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:23:51 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/11 15:23:51 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;
	t_list *list;

	if (alst == NULL || del == NULL)
		return ;
	list = *alst;
	while (list)
	{
		temp = list->next;
		del(list->content, list->content_size);
		free(list);
		list = temp;
	}
	*alst = NULL;
}
