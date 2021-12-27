/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:33:48 by khansman          #+#    #+#             */
/*   Updated: 2016/11/25 09:34:01 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

int		free_lst(t_list *list)
{
	t_list			*tmp;
	unsigned int	k;

	k = 0;
	while (list != NULL)
	{
		if (list->content_size > 0 && list->content != NULL)
			free(list->content);
		tmp = list;
		list = list->next;
		free(tmp);
		k++;
	}
	return (k);
}

int		safe_free_lst(t_list **list)
{
	int		k;

	if (list == NULL)
		return (-1);
	k = free_lst(*list);
	*list = NULL;
	return (k);
}

int		safe_free(void **item)
{
	if (item == NULL)
		return (-1);
	if (*item == NULL)
		return (0);
	free(*item);
	*item = NULL;
	return (1);
}
