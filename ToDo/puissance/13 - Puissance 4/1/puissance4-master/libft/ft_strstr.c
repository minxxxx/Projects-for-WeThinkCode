/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:50:29 by telain            #+#    #+#             */
/*   Updated: 2015/12/17 17:36:55 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *str2)
{
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (str2[0] == '\0')
		return ((char*)str);
	while (str[i])
	{
		while (str2[i2] == str[i + i2])
		{
			if (str2[i2] == '\0')
				return ((char *)str + i);
			i2++;
		}
		if (str2[i2] == '\0')
			return ((char *)str + i);
		i2 = 0;
		i++;
	}
	return (NULL);
}
