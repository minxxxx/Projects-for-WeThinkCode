/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 10:36:29 by thou              #+#    #+#             */
/*   Updated: 2016/11/17 10:43:58 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*src;
	char			*dst;
	unsigned int	i;

	src = (char*)s;
	if (!src)
		return (NULL);
	dst = malloc(ft_strlen(src) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = f(i, src[i]);
		i++;
	}
	dst[i] = 0;
	return (dst);
}
