/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:30:13 by pmartine          #+#    #+#             */
/*   Updated: 2015/11/30 20:35:47 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dstcpy;
	unsigned char	*srccpy;

	i = 0;
	dstcpy = (unsigned char *)dst;
	srccpy = (unsigned char *)src;
	if (dstcpy > srccpy)
	{
		while (i < len)
		{
			dstcpy[len - 1] = srccpy[len - 1];
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			dstcpy[i] = srccpy[i];
			i++;
		}
	}
	return (dst);
}
