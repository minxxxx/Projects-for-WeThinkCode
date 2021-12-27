/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glarivie <glarivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 11:54:27 by glarivie          #+#    #+#             */
/*   Updated: 2015/11/24 08:23:54 by glarivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		index;
	size_t		ret;

	ret = ft_strlen(src);
	index = 0;
	while (dst[index] && index < size)
		index++;
	ret += ((index < size) ? index : size);
	if ((int)(size - ft_strlen(dst) - 1) > 0)
		ft_strncat(dst, (char *)src, size - ft_strlen(dst) - 1);
	return (ret);
}
