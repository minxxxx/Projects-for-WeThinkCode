/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:06:42 by fkuhn             #+#    #+#             */
/*   Updated: 2018/11/28 14:35:06 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alist, void (*del)(void *, size_t))
{
	if (alist && del)
	{
		del((*alist)->content, (*alist)->content_size);
		free(*alist);
		*alist = NULL;
	}
}
