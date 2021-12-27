/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:28:02 by telain            #+#    #+#             */
/*   Updated: 2015/12/02 14:49:37 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	i2;

	i = 0;
	while (dst[i] && i < size)
		i++;
	i2 = i;
	while (src[i - i2] && i < size - 1)
	{
		dst[i] = src[i - i2];
		i++;
	}
	if (i2 < size)
		dst[i] = '\0';
	return (i2 + ft_strlen(src));
}
