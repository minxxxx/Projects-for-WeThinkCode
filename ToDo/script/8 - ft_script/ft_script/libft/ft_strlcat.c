/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 20:24:12 by wide-aze          #+#    #+#             */
/*   Updated: 2014/11/10 15:20:50 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len;

	len_dst = ft_strlen((const char*)dst);
	len = ft_strlen(src) + len_dst;
	if (size >= len_dst + 2)
		ft_strncat(dst, src, size - len_dst - 1);
	if (size > len_dst)
		return (len);
	else
		return (len - (len_dst - size));
}
