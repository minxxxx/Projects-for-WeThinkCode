/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:50:58 by thendric          #+#    #+#             */
/*   Updated: 2016/11/08 22:57:01 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (lst)
	{
		if (!content || !content_size)
		{
			lst->content = NULL;
			lst->content_size = 0;
		}
		else
		{
			lst->content_size = content_size;
			lst->content = ft_memalloc(content_size);
			if (lst->content)
				lst->content = ft_memmove(lst->content, content, content_size);
		}
		lst->next = NULL;
	}
	return (lst);
}
