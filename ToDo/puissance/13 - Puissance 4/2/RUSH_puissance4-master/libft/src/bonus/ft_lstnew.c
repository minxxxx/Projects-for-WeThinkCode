/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:29:27 by thou              #+#    #+#             */
/*   Updated: 2016/11/18 17:49:09 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*dst;

	dst = (t_list*)malloc(sizeof(t_list));
	if (dst == NULL)
		return (NULL);
	if (content == NULL)
	{
		dst->content_size = 0;
		dst->content = NULL;
	}
	else
	{
		dst->content_size = content_size;
		dst->content = malloc(content_size);
		ft_memcpy(dst->content, content, content_size);
	}
	dst->next = NULL;
	return (dst);
}
