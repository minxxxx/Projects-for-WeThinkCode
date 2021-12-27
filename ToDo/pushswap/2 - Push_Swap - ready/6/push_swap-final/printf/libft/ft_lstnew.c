/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   es1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:57:24 by cfavero           #+#    #+#             */
/*   Updated: 2018/01/30 16:04:05 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*a;

	if (!(a = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content && content_size > 0)
	{
		if (!(a->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(a->content, content, content_size);
		a->content_size = content_size;
	}
	else
	{
		a->content = NULL;
		a->content_size = 0;
	}
	a->next = NULL;
	return (a);
}
