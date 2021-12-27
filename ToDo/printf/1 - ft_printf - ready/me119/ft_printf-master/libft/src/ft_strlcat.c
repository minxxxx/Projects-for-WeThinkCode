/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:39:16 by opodolia          #+#    #+#             */
/*   Updated: 2016/12/01 16:33:07 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	end;

	i = 0;
	j = 0;
	while (i < size && dst[i])
		i++;
	while (src[j])
		j++;
	end = i;
	while (i < size - 1 && src[i - end])
	{
		dst[i] = src[i - end];
		i++;
	}
	if (end < size)
		dst[i] = '\0';
	return (end + j);
}
