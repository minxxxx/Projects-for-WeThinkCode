/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:05:37 by thou              #+#    #+#             */
/*   Updated: 2016/12/15 17:21:10 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinchar(char const *s1, char c)
{
	char	*dst;
	size_t	i;
	size_t	len;

	if (!s1 || !c)
		return (NULL);
	len = ft_strlen(s1);
	dst = ft_strnew(len + 2);
	if (!dst)
		return (NULL);
	i = -1;
	while (++i < len)
		*(dst + i) = *(s1 + i);
	*(dst + i) = c;
	*(dst + i + 1) = 0;
	return (dst);
}
