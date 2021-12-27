/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:22:23 by thou              #+#    #+#             */
/*   Updated: 2016/11/10 15:04:42 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;
	int				i;
	unsigned char	b;

	i = 0;
	a = (unsigned char*)s;
	b = c;
	while (n--)
	{
		if (*a == b)
			return (a += i);
		a++;
	}
	return (NULL);
}
