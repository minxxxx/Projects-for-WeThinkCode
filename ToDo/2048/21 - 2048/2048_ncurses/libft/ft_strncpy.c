/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 10:43:57 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/24 08:13:48 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	index;
	size_t	length;

	index = -1;
	length = ft_strlen(src);
	while (++index < n)
	{
		if (index > length)
			dst[index] = '\0';
		else
			dst[index] = src[index];
	}
	return (dst);
}
