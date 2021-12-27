/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:14:35 by thou              #+#    #+#             */
/*   Updated: 2016/11/13 11:12:01 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *d;

	d = (char*)s1;
	s1 += ft_strlen(s1);
	if (n <= ft_strlen(s2))
	{
		s1[n] = '\0';
		ft_memcpy(s1 + ft_strlen(s1), s2, n);
	}
	else
		ft_strcat(s1, s2);
	return (d);
}
