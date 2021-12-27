/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:52:47 by cfavero           #+#    #+#             */
/*   Updated: 2017/11/22 18:23:12 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int h;
	int a;

	a = 0;
	h = 0;
	if (needle[a] == '\0')
		return ((char *)haystack);
	while (haystack[h])
	{
		a = 0;
		while (haystack[h + a] == needle[a] && needle[a] != '\0')
			a++;
		if (needle[a] == '\0')
		{
			haystack = haystack + h;
			return ((char*)haystack);
		}
		h++;
	}
	return (NULL);
}
