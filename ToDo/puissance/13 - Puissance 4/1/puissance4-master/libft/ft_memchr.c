/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:04:13 by telain            #+#    #+#             */
/*   Updated: 2015/11/30 17:42:23 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	temp = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (temp[i] == (unsigned char)c)
			return ((void*)&s[i]);
		i++;
	}
	return (NULL);
}
