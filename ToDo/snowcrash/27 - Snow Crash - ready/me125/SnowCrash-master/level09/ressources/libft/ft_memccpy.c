/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:54:47 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/01 05:07:48 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	d;
	unsigned char	*srce;
	unsigned char	*dest;

	i = 0;
	d = (unsigned char)c;
	srce = (unsigned char *)src;
	dest = (unsigned char *)dst;
	while (i < n && srce[i] != d)
	{
		dest[i] = srce[i];
		i++;
	}
	if (i == n)
		return (NULL);
	if (srce[i] == d)
	{
		dest[i] = srce[i];
		i++;
	}
	return ((void *)&dest[i]);
}
