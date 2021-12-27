/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:24:40 by dtedgui           #+#    #+#             */
/*   Updated: 2015/12/01 13:44:20 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*dst_pt;
	unsigned char	*src_pt;

	if (!dst || !src)
		return (NULL);
	ch = (unsigned char)c;
	dst_pt = (unsigned char*)dst;
	src_pt = (unsigned char*)src;
	while (n-- > 0)
	{
		*dst_pt = *src_pt;
		if (*dst_pt++ == ch)
			return (dst_pt);
		src_pt++;
	}
	return (NULL);
}
