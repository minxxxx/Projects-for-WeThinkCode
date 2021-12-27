/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:01:33 by jtranchi          #+#    #+#             */
/*   Updated: 2015/12/08 11:28:00 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dst,
const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	x;

	s1 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	x = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if ((*s1++ = *s2++) == x)
			return (s1);
		i++;
	}
	return (NULL);
}
