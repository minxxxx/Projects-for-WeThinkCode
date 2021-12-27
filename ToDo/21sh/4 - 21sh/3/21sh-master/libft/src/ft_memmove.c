/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:58:56 by fkoehler          #+#    #+#             */
/*   Updated: 2015/11/28 12:30:09 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr_src;
	char	*ptr_dst;
	int		i;

	ptr_src = (char *)src;
	ptr_dst = (char *)dst;
	i = 0;
	while (len > 0)
	{
		if (src < dst)
		{
			ptr_dst[len - 1] = ptr_src[len - 1];
			len--;
		}
		if (src > dst)
		{
			ptr_dst[i] = ptr_src[i];
			i++;
			len--;
		}
	}
	return (dst);
}
