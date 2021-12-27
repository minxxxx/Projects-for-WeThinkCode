/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:57:15 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/11 12:57:16 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*mdst;
	unsigned char	*msrc;
	unsigned char	t;

	mdst = (unsigned char*)dst;
	msrc = (unsigned char*)src;
	t = (unsigned char)c;
	while (n--)
	{
		*(mdst)++ = *(msrc)++;
		if (*(msrc - 1) == t)
			return (mdst);
	}
	return (NULL);
}
