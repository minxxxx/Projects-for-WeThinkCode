/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:59:59 by pmartine          #+#    #+#             */
/*   Updated: 2015/12/01 18:23:25 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s2 = (unsigned char*)s;
	while (n > 0)
	{
		if (*s2 == (unsigned char)c)
			return ((void *)s2);
		s2++;
		n--;
	}
	return (NULL);
}
