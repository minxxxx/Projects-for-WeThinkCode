/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frontaddlink.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftait <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 11:16:54 by ftait             #+#    #+#             */
/*   Updated: 2017/11/24 02:52:41 by ftait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

t_list		*frontaddlink(t_list *list, char *str)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->content = str;
		tmp->next = list;
	}
	return (tmp);
}
