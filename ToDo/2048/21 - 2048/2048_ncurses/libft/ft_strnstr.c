/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:52:41 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/27 14:56:43 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *s1, char const *s2, size_t n)
{
	char	c;
	char	stmp;
	size_t	len;
	int		t;

	t = 0;
	if ((c = *s2++) != '\0')
	{
		len = ft_strlen(s2);
		while (!t || ft_strncmp(s1, s2, len) != 0)
		{
			t = 1;
			if ((stmp = *s1++) == '\0' || n-- < 1)
				return (NULL);
			while (stmp != c)
			{
				if ((stmp = *s1++) == '\0' || n-- < 1)
					return (NULL);
			}
			if (len > n)
				return (NULL);
		}
		s1--;
	}
	return ((char *)s1);
}
