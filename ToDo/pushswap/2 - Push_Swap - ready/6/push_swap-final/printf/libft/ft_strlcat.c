/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:32:00 by cfavero           #+#    #+#             */
/*   Updated: 2017/11/22 14:48:14 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_size;
	size_t src_size;
	size_t n;
	size_t i;

	src_size = ft_strlen(src);
	dst_size = ft_strlen(dst);
	if (dst_size > size)
		dst_size = size;
	n = dst_size + src_size;
	if (size > dst_size)
	{
		i = 0;
		while (((dst_size + i) < (size - 1)) && src[i])
		{
			dst[dst_size + i] = src[i];
			i++;
		}
		dst[dst_size + i] = '\0';
	}
	return (n);
}
