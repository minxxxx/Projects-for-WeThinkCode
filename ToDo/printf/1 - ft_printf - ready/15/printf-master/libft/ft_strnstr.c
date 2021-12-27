/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:20:18 by fkuhn             #+#    #+#             */
/*   Updated: 2018/11/29 22:08:56 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	const char	*ptr;
	const char	*tmp;

	i = 0;
	ptr = haystack + len;
	if (!*needle)
		return ((char *)haystack);
	if (needle == haystack)
		return ((char *)haystack);
	while (*haystack && haystack != ptr)
	{
		tmp = haystack;
		while (*haystack && *haystack == needle[i] && haystack != ptr)
		{
			i++;
			++haystack;
		}
		haystack = tmp;
		if (!needle[i])
			return ((char *)haystack);
		i = 0;
		haystack++;
	}
	return (NULL);
}
