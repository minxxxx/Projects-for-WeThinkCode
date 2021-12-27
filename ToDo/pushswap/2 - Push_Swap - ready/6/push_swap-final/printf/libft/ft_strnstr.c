/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:08:34 by cfavero           #+#    #+#             */
/*   Updated: 2017/11/22 18:18:15 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		h;
	size_t	a;

	h = 0;
	if (!*haystack)
		return (0);
	while (haystack[h] && len)
	{
		a = 0;
		while (haystack[h + a] == needle[a] && needle[a] != '\0' && len > a)
			a++;
		if (needle[a] == '\0')
		{
			haystack = haystack + h;
			return ((char*)haystack);
		}
		h++;
		len--;
	}
	return (NULL);
}
