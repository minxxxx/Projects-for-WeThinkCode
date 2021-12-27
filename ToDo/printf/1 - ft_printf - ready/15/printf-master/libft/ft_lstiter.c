/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:40:33 by fkuhn             #+#    #+#             */
/*   Updated: 2018/11/28 17:32:56 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*curr;
	t_list	*next;

	if (lst && f)
	{
		curr = lst;
		while (curr)
		{
			next = curr->next;
			f(curr);
			curr = next;
		}
	}
}
