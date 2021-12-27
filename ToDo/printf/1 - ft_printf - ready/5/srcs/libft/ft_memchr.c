/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <thendric@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 10:03:31 by thendric          #+#    #+#             */
/*   Updated: 2016/11/02 10:16:10 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*str;

	str = (unsigned const char*)s;
	while (n > 0)
	{
		if (*str == (unsigned char)c)
			return ((void*)str);
		str++;
		n--;
	}
	return (NULL);
}
