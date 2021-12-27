/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 09:19:21 by wide-aze          #+#    #+#             */
/*   Updated: 2014/11/11 09:44:04 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	new_list = (t_list*)malloc(sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	new_list->content = malloc(sizeof(void) * content_size);
	if (new_list->content == NULL)
		return (NULL);
	new_list->next = NULL;
	if (!content)
	{
		new_list->content = NULL;
		new_list->content_size = 0;
		return (new_list);
	}
	new_list->content = ft_memcpy(new_list->content, content, content_size);
	new_list->content_size = content_size;
	return (new_list);
}
