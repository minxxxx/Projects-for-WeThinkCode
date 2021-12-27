/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:20:36 by wide-aze          #+#    #+#             */
/*   Updated: 2014/11/09 08:44:31 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*src_cpy;
	char		*tmp;
	char		*dst_cpy;

	dst_cpy = dst;
	src_cpy = src;
	tmp = malloc(sizeof(char) * len);
	if (tmp == NULL)
		return (NULL);
	tmp = ft_memcpy(tmp, src_cpy, len);
	dst_cpy = ft_memcpy(dst_cpy, tmp, len);
	free(tmp);
	return (dst);
}
