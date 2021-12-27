/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:32:10 by fkuhn             #+#    #+#             */
/*   Updated: 2018/11/22 15:40:32 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*dptr;
	unsigned char	*sptr;

	ch = (unsigned char)c;
	dptr = (unsigned char *)dst;
	sptr = (unsigned char *)src;
	while (n)
	{
		*dptr = *sptr;
		if (*sptr == ch)
			return (dptr + 1);
		++dptr;
		++sptr;
		--n;
	}
	return (NULL);
}
