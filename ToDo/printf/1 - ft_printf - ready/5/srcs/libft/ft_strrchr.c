/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <thendric@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:55:35 by thendric          #+#    #+#             */
/*   Updated: 2016/11/06 23:38:28 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			len;
	const char	*str;

	len = 0;
	str = s;
	while (*str)
	{
		str++;
		len++;
	}
	if (*str == '\0' && *str == (unsigned char)c)
		return ((char*)str);
	while (len >= 0)
	{
		if (*str == (unsigned char)c)
			return ((char*)str);
		str--;
		len--;
	}
	return (NULL);
}
