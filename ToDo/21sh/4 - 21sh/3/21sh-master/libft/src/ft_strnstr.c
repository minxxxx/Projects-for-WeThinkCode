/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:38:09 by fkoehler          #+#    #+#             */
/*   Updated: 2015/12/07 15:23:55 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s2[j])
		return ((char *)s1);
	while (s1[i] && i < len)
	{
		while (s1[i] && s1[i] != s2[j] && i < len)
			i++;
		while (s1[i] && s2[j] && s1[i] == s2[j] && i < len)
		{
			i++;
			j++;
		}
		if (!s2[j])
			return ((char *)s1 + i - j);
		if (s1[i])
			i = (i - j + 1);
		j = 0;
	}
	return (NULL);
}
