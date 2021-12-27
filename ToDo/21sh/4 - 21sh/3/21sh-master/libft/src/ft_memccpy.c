/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:53:28 by fkoehler          #+#    #+#             */
/*   Updated: 2015/12/08 18:19:45 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*ptr_src;
	char			*ptr_dst;
	unsigned char	uc;
	int				i;

	i = 0;
	ptr_src = (char *)src;
	ptr_dst = (char *)dst;
	uc = (unsigned char)c;
	while (n > 0)
	{
		ptr_dst[i] = ptr_src[i];
		if ((unsigned char)ptr_src[i] == uc)
			return (dst + i + 1);
		i++;
		n--;
	}
	return (NULL);
}
