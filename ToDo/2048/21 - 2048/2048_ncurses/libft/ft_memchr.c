/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 15:48:34 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/25 10:19:01 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;

	index = 0;
	if (!s)
		return (NULL);
	while (index < n && s)
	{
		if (*((char *)s + index) == (char)c)
			return ((void *)((char *)s + index));
		index++;
	}
	return (NULL);
}
