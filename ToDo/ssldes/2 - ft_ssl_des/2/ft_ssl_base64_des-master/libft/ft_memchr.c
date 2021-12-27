/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:02:11 by jtranchi          #+#    #+#             */
/*   Updated: 2016/01/28 18:31:21 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int i;

	i = 0;
	while ((size_t)i < n)
	{
		if ((unsigned char)c == ((unsigned char *)s)[i])
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
