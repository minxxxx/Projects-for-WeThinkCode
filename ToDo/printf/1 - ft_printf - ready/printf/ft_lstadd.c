/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:19:47 by sasiedu           #+#    #+#             */
/*   Updated: 2016/05/23 10:06:11 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list		*temp;

	if (alst == NULL)
		*alst = new;
	else
	{
		temp = new;
		if (temp->next != NULL)
			temp = temp->next;
		temp->next = *alst;
		*alst = new;
	}
}
