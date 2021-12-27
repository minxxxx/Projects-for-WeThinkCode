/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:19:05 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:19:08 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char*)(s1 - 1);
	ptr2 = (unsigned char*)(s2 - 1);
	if (!n)
		return (0);
	while ((--n) + 1 && *(++ptr1) == *(++ptr2))
		;
	return (*ptr1 - *ptr2);
}
