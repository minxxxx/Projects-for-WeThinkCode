/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:29:51 by thou              #+#    #+#             */
/*   Updated: 2016/11/14 16:59:31 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*src;
	char	*dst;

	src = (char*)s;
	dst = src;
	while (*src)
	{
		if (*src == c)
			dst = src;
		src++;
	}
	if (c == 0)
		return (src);
	return (*dst == c ? dst : NULL);
}
