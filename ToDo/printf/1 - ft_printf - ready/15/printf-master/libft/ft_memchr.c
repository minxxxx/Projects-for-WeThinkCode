/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:28:20 by fkuhn             #+#    #+#             */
/*   Updated: 2018/11/22 16:31:33 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*sptr;

	ch = (unsigned char)c;
	sptr = (unsigned char *)s;
	while (n)
	{
		if (*sptr == ch)
			return (sptr);
		--n;
		++sptr;
	}
	return (NULL);
}
