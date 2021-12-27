/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:55:59 by dtedgui           #+#    #+#             */
/*   Updated: 2015/12/14 16:03:03 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_p;
	const char	*src_p;

	if (!dst || !src)
		return (NULL);
	dst_p = dst;
	src_p = src;
	while (n-- > 0)
		*dst_p++ = *src_p++;
	return (dst);
}
