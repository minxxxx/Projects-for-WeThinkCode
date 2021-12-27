/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 14:30:28 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/10 16:34:44 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *new_one;

	new_one = ft_list_create_elem(data);
	if (*begin_list == NULL)
		*begin_list = new_one;
	else
		ft_list_find_end(*begin_list)->next = new_one;
}
