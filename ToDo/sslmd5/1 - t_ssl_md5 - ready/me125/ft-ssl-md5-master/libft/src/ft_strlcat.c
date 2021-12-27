/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:11:35 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/11 13:11:35 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	a;
	size_t	dstcount;

	a = 0;
	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	while (*(dst + a) != '\0' && a < dstsize)
		a++;
	dstcount = a;
	if (dstsize != 0)
	{
		while (*(src + a - dstcount) && a < dstsize - 1)
		{
			*(dst + a) = *(src + a - dstcount);
			a++;
		}
	}
	if (dstcount < dstsize)
		*(dst + a) = '\0';
	return (dstcount + ft_strlen(src));
}
