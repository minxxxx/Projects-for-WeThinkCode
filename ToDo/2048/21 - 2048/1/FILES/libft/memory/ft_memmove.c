/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:31:35 by dtedgui           #+#    #+#             */
/*   Updated: 2015/12/01 11:47:31 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp;

	if (!dst || !src || dst == src || len == 0)
		return (NULL);
	tmp = (unsigned char*)malloc(sizeof(*tmp) * len);
	ft_memcpy(tmp, src, len);
	ft_memcpy(dst, tmp, len);
	free(tmp);
	return (dst);
}
