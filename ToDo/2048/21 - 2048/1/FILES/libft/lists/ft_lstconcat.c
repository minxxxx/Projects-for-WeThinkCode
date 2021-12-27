/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstconcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 10:06:46 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/18 10:13:36 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstconcat(t_list *lnk_first_list, t_list *head_second_list)
{
	if (lnk_first_list && head_second_list)
	{
		while (lnk_first_list->next)
			lnk_first_list = lnk_first_list->next;
		lnk_first_list->next = head_second_list;
	}
}
