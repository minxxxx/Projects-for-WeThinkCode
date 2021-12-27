/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:49:10 by opodolia          #+#    #+#             */
/*   Updated: 2016/11/30 18:44:56 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*dest;
	unsigned const char		*source;
	unsigned char			c1;

	dest = dst;
	source = src;
	c1 = c;
	while (n--)
	{
		*dest++ = *source;
		if (c1 == *source++)
			return (dest);
	}
	return (0);
}
