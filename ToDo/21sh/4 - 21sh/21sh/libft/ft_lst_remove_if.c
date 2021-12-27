/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 12:27:20 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/24 13:46:26 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_remove_if(t_list **begin_lst, void *data, int (*cmp)())
{
	t_list	*temp;

	if (*begin_lst != NULL)
	{
		if (cmp((*begin_lst)->content, data) == 0)
		{
			temp = *begin_lst;
			*begin_lst = (*begin_lst)->next;
			ft_lstdelone(&temp, ft_del);
		}
		else
			ft_lst_remove_if(&(*begin_lst)->next, data, cmp);
	}
}
