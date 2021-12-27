/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <thendric@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 09:56:52 by thendric          #+#    #+#             */
/*   Updated: 2016/11/06 23:24:08 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned const char	*s;

	i = 0;
	d = (unsigned char*)dst;
	s = (unsigned const char*)src;
	while (i < n)
	{
		*d++ = *s;
		if (*s++ == (unsigned char)c)
			return (d);
		i++;
	}
	return (NULL);
}
