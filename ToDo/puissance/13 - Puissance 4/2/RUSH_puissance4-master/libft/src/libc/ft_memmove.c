/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:43:27 by thou              #+#    #+#             */
/*   Updated: 2016/11/10 14:18:29 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*a;
	char	*b;

	a = (char*)src;
	b = (char*)dst;
	if (a > b)
	{
		while (len--)
			*b++ = *a++;
	}
	else if (b > a)
	{
		b += len - 1;
		a += len - 1;
		while (len--)
			*b-- = *a--;
	}
	return (dst);
}
