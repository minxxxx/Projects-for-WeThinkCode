/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 19:10:56 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/01 05:07:59 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	d;
	unsigned char	*ptr;

	i = 0;
	d = (unsigned char)c;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == d)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
