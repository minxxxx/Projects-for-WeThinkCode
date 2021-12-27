/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 14:49:33 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/23 16:39:16 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	size_t	index;
	char	*dst_cpy;
	char	*src_cpy;

	if (!dst || !src)
		return (NULL);
	dst_cpy = (char *)dst;
	src_cpy = (char *)src;
	index = -1;
	while (++index < n)
		dst_cpy[index] = src_cpy[index];
	return (dst);
}
