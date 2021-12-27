/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:41:12 by thou              #+#    #+#             */
/*   Updated: 2016/11/10 11:42:35 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst,
		const void *src, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	unsigned char	ch;
	size_t			i;

	ch = c;
	a = (unsigned char*)src;
	b = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		b[i] = a[i];
		if (a[i++] == ch)
			return (b + i);
	}
	return (NULL);
}
