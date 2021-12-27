/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:11:32 by fkuhn             #+#    #+#             */
/*   Updated: 2018/11/30 14:37:30 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dptr;
	char	*sptr;

	dptr = (char *)dst;
	sptr = (char *)src;
	if (dptr > sptr)
	{
		while (len--)
			*(dptr + len) = *(sptr + len);
	}
	else
	{
		while (len--)
		{
			*dptr = *sptr;
			++sptr;
			++dptr;
		}
	}
	return (dst);
}
