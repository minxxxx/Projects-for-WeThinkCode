/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:20:08 by cfavero           #+#    #+#             */
/*   Updated: 2017/11/22 14:46:48 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c,
		size_t n)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	while (n--)
	{
		*s1++ = *s2;
		if ((unsigned char)*s2++ == (unsigned char)c)
			return (s1);
	}
	return (NULL);
}
