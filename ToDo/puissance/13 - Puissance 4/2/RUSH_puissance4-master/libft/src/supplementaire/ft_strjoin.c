/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:08:47 by thou              #+#    #+#             */
/*   Updated: 2016/11/18 17:19:37 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	char	*b;
	char	*dst;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	dst = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	a = (char*)s1;
	b = (char*)s2;
	while (*a)
		dst[i++] = *(a++);
	while (*b)
		dst[i++] = *(b++);
	dst[i] = 0;
	return (dst);
}
