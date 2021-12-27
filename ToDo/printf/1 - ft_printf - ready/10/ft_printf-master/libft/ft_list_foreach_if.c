/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 15:46:06 by tfleming          #+#    #+#             */
/*   Updated: 2014/12/11 15:46:46 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_list_foreach_if(t_list *list
								, void (*function)(void *)
								, void *data_ref
								, int (*compare)())
{
	while (list)
	{
		if (compare(list->data, data_ref))
			function(list->data);
		list = list->next;
	}
}
