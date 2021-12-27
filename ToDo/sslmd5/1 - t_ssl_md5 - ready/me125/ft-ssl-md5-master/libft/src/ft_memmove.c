/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:57:56 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/11 12:57:57 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			a;
	unsigned char	*mdst;
	unsigned char	*msrc;

	mdst = (unsigned char*)dst;
	msrc = (unsigned char*)src;
	a = 0;
	if (src > dst)
		while (n--)
		{
			*(mdst + a) = *(msrc + a);
			a++;
		}
	else
		while (n--)
			mdst[n] = msrc[n];
	return (dst);
}
