/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:49:06 by cfavero           #+#    #+#             */
/*   Updated: 2017/11/20 18:19:33 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *s1;
	char *s2;

	s1 = (char*)dst;
	s2 = (char*)src;
	if (s2 > s1)
		ft_memcpy(s1, s2, len);
	else if (s2 < s1)
	{
		while (len)
		{
			s1[len - 1] = s2[len - 1];
			len--;
		}
	}
	return (dst);
}
