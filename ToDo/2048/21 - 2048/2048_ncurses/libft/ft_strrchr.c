/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/14 20:05:31 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/24 08:30:40 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;

	index = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)s + index);
	while (s[--index])
	{
		if (s[index] == (char)c)
			return ((char *)s + index);
	}
	return (NULL);
}
