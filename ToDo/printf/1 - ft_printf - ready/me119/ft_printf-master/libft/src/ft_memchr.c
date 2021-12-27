/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:50:45 by opodolia          #+#    #+#             */
/*   Updated: 2016/11/30 19:01:12 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *pointer;

	pointer = (unsigned char *)s;
	while (n--)
		if (*pointer != (unsigned char)c)
			pointer++;
		else
			return (pointer);
	return (0);
}
