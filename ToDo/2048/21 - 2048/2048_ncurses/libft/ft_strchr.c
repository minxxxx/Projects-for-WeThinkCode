/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/14 20:05:31 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/27 14:52:49 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		index;

	index = -1;
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[++index])
	{
		if (s[index] == (char)c)
			return ((char *)s + index);
	}
	return (NULL);
}
