/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 15:11:06 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/23 16:00:33 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	size_t	index;
	char	*dst_cpy;
	char	*src_cpy;

	if (!dst || !src)
		return (NULL);
	dst_cpy = (char *)dst;
	src_cpy = (char *)src;
	index = 0;
	while (n > 0)
	{
		dst_cpy[index] = src_cpy[index];
		if (src_cpy[index] == c)
			return (dst_cpy + index + 1);
		index++;
		n--;
	}
	return (NULL);
}
