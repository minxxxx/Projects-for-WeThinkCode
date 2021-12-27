/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 21:19:58 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/10 21:44:37 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == NULL)
		return (NULL);
	if (cmp(begin_list->data, data_ref) == 0)
		return (begin_list);
	return (ft_list_find(begin_list->next, data_ref, cmp));
}
