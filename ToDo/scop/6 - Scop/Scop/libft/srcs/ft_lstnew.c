/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 15:03:24 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/26 09:24:18 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	size_t	i;

	list = malloc(sizeof(t_list));
	if (!list)
		return (list);
	if (content)
	{
		list->content = malloc(content_size);
		if (list->content)
		{
			i = 0;
			while (++i < content_size + 1)
				((unsigned char*)list->content)[i - 1] =
					((unsigned char*)content)[i - 1];
		}
		list->content_size = content_size;
	}
	else
	{
		list->content = NULL;
		list->content_size = 0;
	}
	list->next = NULL;
	return (list);
}
