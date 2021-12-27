/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:44:33 by telain            #+#    #+#             */
/*   Updated: 2015/12/17 17:25:44 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	unsigned char	letter;

	tmp1 = (unsigned char*)dst;
	tmp2 = (unsigned char*)src;
	letter = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if ((*tmp1++ = *tmp2++) == letter)
			return (tmp1);
		i++;
	}
	return (NULL);
}
