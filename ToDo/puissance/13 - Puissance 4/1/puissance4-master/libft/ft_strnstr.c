/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:26:12 by telain            #+#    #+#             */
/*   Updated: 2015/12/17 17:37:52 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *str2, size_t n)
{
	size_t		i;
	size_t		i2;

	i = 0;
	i2 = 0;
	while (str[i] && i < n)
	{
		while (str2[i2] == str[i + i2] && i + i2 < n)
		{
			if (str2[i2] == '\0')
				return ((char*)str + i);
			i2++;
		}
		if (!str2[i2])
			return ((char*)str + i);
		i2 = 0;
		i++;
	}
	return (NULL);
}
