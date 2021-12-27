/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:01:54 by opodolia          #+#    #+#             */
/*   Updated: 2016/11/30 19:13:11 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char *val1;
	unsigned const char *val2;

	val1 = s1;
	val2 = s2;
	while (n--)
	{
		if (*val1 != *val2)
			return (*val1 - *val2);
		val1++;
		val2++;
	}
	return (0);
}
