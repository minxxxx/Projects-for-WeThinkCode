/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 12:00:55 by pmartine          #+#    #+#             */
/*   Updated: 2015/12/03 14:16:42 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*c;

	c = (void *)ft_memalloc(content_size);
	if (!c)
		return (NULL);
	if (content == NULL)
	{
		c = NULL;
		content_size = 0;
	}
	else
		c = ft_memcpy(c, content, content_size);
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->content = c;
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
