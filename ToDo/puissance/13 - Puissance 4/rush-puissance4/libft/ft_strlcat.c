/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:09:55 by pmartine          #+#    #+#             */
/*   Updated: 2015/11/30 19:36:15 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	result;
	size_t	i;
	size_t	j;

	result = ft_strlen(dst) + ft_strlen(src);
	i = 0;
	j = 0;
	while (dst[i] != 0 && i < size)
		i = i + 1;
	if (size - i == 0)
		return (i + ft_strlen(src));
	while (i != (size - 1) && src[j] != 0)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (result);
}
