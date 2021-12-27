/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <thendric@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:29:46 by thendric          #+#    #+#             */
/*   Updated: 2016/11/14 16:22:23 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	char	*d;

	i = 0;
	d = dst;
	while (*src && i < len)
	{
		*dst++ = *src++;
		i++;
	}
	while (i < len)
	{
		*dst++ = '\0';
		i++;
	}
	return (d);
}
