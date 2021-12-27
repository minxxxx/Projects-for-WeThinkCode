/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:15:40 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:15:44 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*cpy;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	cpy = (void *)content;
	if (cpy == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = (void*)malloc(content_size);
		ft_memcpy(new->content, cpy, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
