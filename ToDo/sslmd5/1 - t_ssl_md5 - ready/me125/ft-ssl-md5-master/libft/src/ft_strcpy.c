/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:04:12 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/11 13:04:12 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpy(char *dst, const char *src)
{
	int a;

	a = 0;
	while (src[a] != '\0')
	{
		dst[a] = src[a];
		a++;
	}
	dst[a] = '\0';
	return (dst);
}

void		ft_strscpy(char *dst, const char *src, char stop)
{
	int a;

	a = 0;
	while (src[a] != stop)
	{
		dst[a] = src[a];
		a++;
	}
	dst[a] = '\0';
}
