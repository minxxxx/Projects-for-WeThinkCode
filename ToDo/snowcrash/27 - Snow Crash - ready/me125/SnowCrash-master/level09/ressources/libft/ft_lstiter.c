/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 13:28:41 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/01 05:06:56 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_lstiter(t_list *alst, void (*f)(t_list *elem))
{
	t_list *tmp;

	tmp = alst;
	if (!alst || !f)
		return ;
	while (tmp)
	{
		f(tmp);
		tmp = tmp->next;
	}
}
