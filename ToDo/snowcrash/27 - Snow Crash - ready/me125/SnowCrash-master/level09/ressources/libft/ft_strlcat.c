/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:27:21 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/01 05:12:36 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dst;

	i = 0;
	while (dest[i] && i < size)
		i++;
	dst = i;
	while (src[i - dst] && size - 1 > i)
	{
		dest[i] = src[i - dst];
		i++;
	}
	if (size > dst)
		dest[i] = '\0';
	return (dst + ft_strlen(src));
}
