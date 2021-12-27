/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 11:41:40 by thou              #+#    #+#             */
/*   Updated: 2017/03/28 17:45:40 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*a;
	char	*dst;
	int		i;

	a = (char*)s;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	dst = (char*)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	a += start;
	i = 0;
	while (len--)
		dst[i++] = *(a++);
	dst[i] = 0;
	return (dst);
}
