/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 09:06:06 by sasiedu           #+#    #+#             */
/*   Updated: 2016/05/23 07:58:23 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *restrict dst, const void *restrict src, \
		int c, size_t n)
{
	size_t				i;
	unsigned	char	*s1;
	unsigned	char	*s2;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	i = 0;
	while (i < n && s2[i])
	{
		if (s2[i] == (unsigned char)c)
			return (&dst[i + 1]);
		s1[i] = s2[i];
		i++;
	}
	if ((unsigned char)c == '\0' && s2[i] == '\0')
		return (&s2[i]);
	return (NULL);
}
