/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/10 17:15:04 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/10 20:56:44 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_destroy(t_list *list)
{
	if (list->next != NULL)
		ft_destroy(list->next);
	free(list);
}

void			ft_list_clear(t_list **begin_list)
{
	ft_destroy(*begin_list);
	*begin_list = NULL;
}
