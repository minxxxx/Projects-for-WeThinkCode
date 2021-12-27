/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:50:45 by telain            #+#    #+#             */
/*   Updated: 2015/12/17 17:29:02 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*temp;
	unsigned char	*temp2;

	temp = (unsigned char*)dst;
	temp2 = (unsigned char*)src;
	if (dst < src)
		return ((unsigned char*)ft_memcpy(dst, src, len));
	i = len;
	while (i > 0)
	{
		temp[i - 1] = temp2[i - 1];
		i--;
	}
	return ((unsigned char*)dst);
}
