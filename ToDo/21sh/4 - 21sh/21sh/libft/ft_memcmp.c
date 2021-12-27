/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 23:34:05 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/23 00:04:48 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	unsigned char	*a;
	unsigned char	*b;
	
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL)
		return ('\0' - b[0]);
	if (s2 == NULL)
		return (a[0] - '\0');
	i = 0;
	while (i < n)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}
