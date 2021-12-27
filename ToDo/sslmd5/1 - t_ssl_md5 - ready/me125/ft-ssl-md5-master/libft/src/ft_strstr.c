/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:15:01 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/11 13:15:01 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	char	*word;
	size_t	c;
	size_t	i;

	i = 0;
	word = (char*)haystack;
	if (*needle == '\0')
		return (word);
	if (*haystack == '\0')
	{
		if (*needle == '\0')
			return (word);
		return (NULL);
	}
	while (*(haystack + i))
	{
		c = ft_strlen(needle);
		if (*(haystack + i) == needle[c - c])
			if (ft_strncmp(haystack + i, needle, c) == 0)
				return (&word[i]);
		i++;
	}
	return (NULL);
}
