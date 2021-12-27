/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:31:47 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:31:50 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *src, char *from, char *to)
{
	char		*f;
	char		*str;
	size_t		len1;
	size_t		len2;

	str = NULL;
	if ((f = ft_strstr(src, from)))
	{
		len1 = f - src;
		len2 = ft_strlen(f + ft_strlen(from));
		str = ft_memalloc(sizeof(char) * (len1 + ft_strlen(to) + len2 + 1));
		if (str)
		{
			str = ft_strncpy(str, src, len1);
			str = ft_strcat(str, to);
			str = ft_strcat(str, f + ft_strlen(from));
		}
	}
	return (str);
}
