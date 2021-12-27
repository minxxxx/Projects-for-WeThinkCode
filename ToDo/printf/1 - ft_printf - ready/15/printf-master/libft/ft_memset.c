/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:51:04 by fkuhn             #+#    #+#             */
/*   Updated: 2018/11/22 15:13:52 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	ch;

	ch = (unsigned char)c;
	ptr = (unsigned char *)b;
	while (len)
	{
		*ptr = ch;
		--len;
		++ptr;
	}
	return (b);
}
