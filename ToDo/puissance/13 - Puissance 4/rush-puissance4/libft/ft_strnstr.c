/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:50:45 by pmartine          #+#    #+#             */
/*   Updated: 2015/12/01 20:47:08 by pmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		x;
	int		i;
	int		j;

	if (!*s2)
		return ((char *)s1);
	i = 0;
	while (s1[i] && n > 0)
	{
		j = 0;
		if (n < ft_strlen(s2))
			return (NULL);
		x = i;
		while (s1[x] == s2[j] && s2[j] && s1[x])
		{
			j++;
			x++;
		}
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		n--;
		i++;
	}
	return (NULL);
}
