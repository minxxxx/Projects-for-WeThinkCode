/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:29:51 by wide-aze          #+#    #+#             */
/*   Updated: 2014/11/09 08:56:25 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*dst_cpy;
	const char	*src_cpy;

	i = 0;
	dst_cpy = dst;
	src_cpy = src;
	while (i != n)
	{
		dst_cpy[i] = src_cpy[i];
		i++;
		if (dst_cpy[i - 1] == (char)c)
			return (&dst_cpy[i]);
	}
	return (NULL);
}
