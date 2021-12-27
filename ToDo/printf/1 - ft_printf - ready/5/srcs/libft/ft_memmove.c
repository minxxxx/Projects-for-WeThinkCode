/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <thendric@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 09:46:19 by thendric          #+#    #+#             */
/*   Updated: 2016/11/02 09:56:05 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (s < d)
	{
		while ((long)--len >= 0)
			*(d + len) = *(s + len);
	}
	else
		while (i < len)
		{
			*(d + i) = *(s + i);
			i++;
		}
	return (dst);
}
