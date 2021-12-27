/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 11:03:29 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/27 14:53:23 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t a;
	size_t b;

	a = 0;
	b = 0;
	if (!*s2)
		return ((char*)s1);
	while (s1[a])
	{
		while (s1[a + b] && s1[a + b] == s2[b])
			b++;
		if (!s2[b])
			return ((char *)s1 + a);
		else
			b = 0;
		a++;
	}
	return (NULL);
}
