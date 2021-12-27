/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 18:10:10 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/24 18:45:44 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list **lst)
{
	if (*lst != NULL)
	{
		write(1, (*lst)->content, (*lst)->content_size);
		write(1, "\n", 1);
		ft_lstprint(&(*lst)->next);
	}
}
