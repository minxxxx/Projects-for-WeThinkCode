/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:52:52 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/11 14:52:52 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void *ret;

	ret = NULL;
	if (size > 0)
	{
		ret = malloc(size);
		if (ret == NULL)
			return (NULL);
		ret = ft_memset(ret, 0, size);
	}
	return (ret);
}
