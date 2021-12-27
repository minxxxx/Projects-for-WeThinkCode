/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 18:16:13 by tfleming          #+#    #+#             */
/*   Updated: 2014/12/16 19:20:37 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_list_sort(t_list **first, int (*compare)(void*, void*))
{
	int		changed;
	t_list	*current;

	changed = 1;
	while (changed)
	{
		changed = 0;
		current = *first;
		while (current->next)
		{
			if (compare(current->data, current->next->data) > 0)
			{
				ft_ptrswp(&current->data, &current->next->data);
				changed = 1;
			}
			current = current->next;
		}
	}
}
