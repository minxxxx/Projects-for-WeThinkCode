/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:58:30 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/11 12:58:31 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t	a;
	char	*str;

	a = 0;
	str = (char*)s;
	while (a++ < n)
	{
		if (*str == (char)c)
			return ((char*)str);
		str++;
	}
	return (NULL);
}
