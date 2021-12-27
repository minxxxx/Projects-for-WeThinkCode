/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:02:21 by cfavero           #+#    #+#             */
/*   Updated: 2017/11/21 19:16:58 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1k;
	unsigned char	*s2k;
	size_t			i;

	i = 0;
	s1k = (unsigned char*)s1;
	s2k = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (i < (n - 1) && s1k[i] == s2k[i])
		i++;
	if (s1k[i] != s2k[i])
		return (s1k[i] - s2k[i]);
	return (0);
}
