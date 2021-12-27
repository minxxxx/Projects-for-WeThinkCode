/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:58:10 by pmartine          #+#    #+#             */
/*   Updated: 2015/11/30 14:16:19 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*c;
	size_t			i;

	i = 0;
	c = NULL;
	c = (unsigned char *)malloc(size);
	if (c)
	{
		while (size--)
		{
			c[i] = 0;
			i++;
		}
	}
	return ((void *)c);
}
