/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstback.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 11:46:24 by glarivie          #+#    #+#             */
/*   Updated: 2016/01/06 12:10:48 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstback(t_list **begin_list, t_list *new)
{
	t_list		*list;

	list = *begin_list;
	if (list)
	{
		while (list->next != NULL)
			list = list->next;
		list->next = new;
	}
}
