/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:43:23 by fkuhn             #+#    #+#             */
/*   Updated: 2018/11/29 18:52:12 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	if (needle == haystack)
		return ((char *)haystack);
	while (*haystack)
	{
		while (haystack[i] && haystack[i] == needle[i])
			i++;
		if (!needle[i])
			return ((char *)haystack);
		i = 0;
		haystack++;
	}
	return (NULL);
}
