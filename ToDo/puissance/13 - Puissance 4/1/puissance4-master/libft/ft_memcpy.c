/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:39:39 by telain            #+#    #+#             */
/*   Updated: 2015/12/17 17:01:50 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*tmp;
	const char	*tmp2;
	size_t		i;

	i = -1;
	tmp = (char*)dst;
	tmp2 = (const char*)src;
	while (++i < n)
		tmp[i] = tmp2[i];
	return (dst);
}
