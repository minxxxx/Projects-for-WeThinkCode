/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <thendric@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:48:21 by thendric          #+#    #+#             */
/*   Updated: 2016/11/06 23:31:10 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	d_size;
	size_t	s_size;

	i = 0;
	d_size = ft_strlen(dst);
	s_size = ft_strlen(src);
	if (d_size < size)
	{
		while (*dst)
		{
			dst++;
			i++;
		}
		while (*src && i < size - 1)
		{
			*dst++ = *src++;
			i++;
		}
		*dst = '\0';
		return (d_size + s_size);
	}
	return (s_size + size);
}
