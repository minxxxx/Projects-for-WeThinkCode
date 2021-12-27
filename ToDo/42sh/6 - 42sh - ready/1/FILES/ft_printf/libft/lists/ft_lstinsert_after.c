/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert_after.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 13:24:11 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/13 13:57:21 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert_after(t_list *target, t_list *new)
{
	if (target)
	{
		new->next = target->next;
		target->next = new;
	}
}
