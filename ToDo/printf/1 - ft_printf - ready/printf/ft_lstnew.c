/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 13:11:43 by sasiedu           #+#    #+#             */
/*   Updated: 2016/05/11 13:24:01 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*temp;

	temp = (t_list *)malloc(sizeof(t_list));
	if (temp == NULL)
		return (NULL);
	if (content == NULL)
	{
		temp->content = NULL;
		temp->content_size = 0;
	}
	else
	{
		temp->content = (void *)content;
		temp->content_size = content_size;
		temp->next = NULL;
	}
	return (temp);
}
