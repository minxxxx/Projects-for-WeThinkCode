/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:00:51 by jtranchi          #+#    #+#             */
/*   Updated: 2015/11/29 16:00:52 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *restrict dst, const char *restrict src, size_t n)
{
	int i;

	i = 0;
	while (n-- > 0)
		if (*src)
			dst[i++] = *src++;
		else
			dst[i++] = '\0';
	return (dst);
}
