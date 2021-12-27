/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:31:43 by telain            #+#    #+#             */
/*   Updated: 2015/11/30 16:56:08 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;
	int			count;

	i = 0;
	count = 0;
	if (size > ft_strlen(dst))
		return (0);
	while (i < size)
	{
		dst[i] = src[i];
		i++;
		count++;
	}
	return ((size_t)count);
}
