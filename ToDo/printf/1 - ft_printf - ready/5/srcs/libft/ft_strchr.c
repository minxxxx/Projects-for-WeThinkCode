/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <thendric@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:42:29 by thendric          #+#    #+#             */
/*   Updated: 2016/11/06 23:38:13 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s++ == (unsigned char)c)
			return ((char*)--s);
	}
	if (*s == '\0' && *s == (unsigned char)c)
		return ((char*)s);
	return (NULL);
}
