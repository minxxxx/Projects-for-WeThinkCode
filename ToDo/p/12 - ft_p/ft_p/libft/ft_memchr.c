/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:49:32 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/31 08:55:10 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*bytes;
	unsigned char	stop;

	if (!s)
		return (NULL);
	stop = (unsigned char)(unsigned int)c;
	bytes = (unsigned char*)s;
	while (n-- > 0)
	{
		if (*(bytes) == stop)
			return (bytes);
		bytes++;
	}
	return (NULL);
}
