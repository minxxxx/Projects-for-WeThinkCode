/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:59:10 by thou              #+#    #+#             */
/*   Updated: 2016/11/14 12:51:13 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = ft_strlen(src);
	if (len > i)
	{
		ft_memcpy(dst, src, i);
		ft_memset(dst + i, 0, len - i);
		return (dst);
	}
	else
		return (ft_memcpy(dst, src, len));
}
