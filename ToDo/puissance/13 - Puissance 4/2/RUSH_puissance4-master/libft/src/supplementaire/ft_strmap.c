/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 10:23:13 by thou              #+#    #+#             */
/*   Updated: 2016/11/17 10:35:57 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*scr;
	char	*dst;
	int		i;

	scr = (char*)s;
	if (!scr)
		return (NULL);
	dst = malloc(ft_strlen(scr) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (*scr)
		dst[i++] = f(*(scr++));
	dst[i] = 0;
	return (dst);
}
