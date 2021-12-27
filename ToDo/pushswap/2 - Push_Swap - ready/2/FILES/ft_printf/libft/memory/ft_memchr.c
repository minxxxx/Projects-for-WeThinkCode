/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:55:28 by dtedgui           #+#    #+#             */
/*   Updated: 2015/11/30 18:47:47 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*s_ptr;

	if (!s)
		return (NULL);
	ch = (unsigned char)c;
	s_ptr = (unsigned char*)s;
	while (n)
	{
		if (*s_ptr == ch)
			return ((void*)s_ptr);
		s_ptr++;
		n--;
	}
	return (NULL);
}
