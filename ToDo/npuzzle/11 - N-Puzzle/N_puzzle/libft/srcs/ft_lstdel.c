/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 15:11:16 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/20 09:24:09 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*item;
	t_list	*next;

	item = *alst;
	while (item)
	{
		del(item->content, item->content_size);
		next = item->next;
		free(item);
		item = next;
	}
	*alst = NULL;
}
