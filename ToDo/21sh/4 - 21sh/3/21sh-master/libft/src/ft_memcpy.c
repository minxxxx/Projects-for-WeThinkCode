/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:05:57 by fkoehler          #+#    #+#             */
/*   Updated: 2015/11/27 16:42:05 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptr_src;
	char	*ptr_dst;
	int		i;

	i = 0;
	ptr_src = (char *)src;
	ptr_dst = (char *)dst;
	while (n > 0)
	{
		ptr_dst[i] = ptr_src[i];
		i++;
		n--;
	}
	return (dst);
}
