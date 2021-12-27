/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:08:49 by thou              #+#    #+#             */
/*   Updated: 2016/11/10 15:15:12 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *a1;
	unsigned char *a2;

	a1 = (unsigned char*)s1;
	a2 = (unsigned char*)s2;
	while (n--)
	{
		if (*a1 - *a2 == 0)
		{
			a1++;
			a2++;
		}
		else
			return (*a1 - *a2);
	}
	return (0);
}
