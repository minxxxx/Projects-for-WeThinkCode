/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 15:36:32 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/23 16:16:15 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	index;
	char	*dst_cpy;
	char	*src_cpy;

	dst_cpy = (char *)dst;
	src_cpy = (char *)src;
	index = 0;
	if (src_cpy < dst_cpy)
	{
		while (++index <= len)
			dst_cpy[len - index] = src_cpy[len - index];
	}
	else
	{
		while (index < len)
		{
			dst_cpy[index] = src_cpy[index];
			index++;
		}
	}
	return (dst);
}
