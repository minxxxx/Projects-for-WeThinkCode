/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 12:31:24 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/23 18:59:09 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t		len;
	size_t		i;
	size_t		j;

	len = ft_strlen(dst);
	i = 0;
	while (dst[i])
		i++;
	j = 0;
	if (size < len)
		return (ft_strlen(src) + size);
	if (size == len)
		return (len + ft_strlen(src));
	while (src[j] && j < size - len - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len + ft_strlen(src));
}
