/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:56:24 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/11 12:56:24 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			a;
	unsigned char	*mdst;
	unsigned char	*msrc;

	mdst = (unsigned char*)dst;
	msrc = (unsigned char*)src;
	a = 0;
	if (dst == src)
		return (dst);
	while (n > a)
	{
		*(mdst + a) = *(msrc + a);
		a++;
	}
	return (dst);
}
