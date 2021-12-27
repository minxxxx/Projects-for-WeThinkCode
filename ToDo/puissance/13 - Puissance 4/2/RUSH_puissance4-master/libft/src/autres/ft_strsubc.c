/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:09:57 by thou              #+#    #+#             */
/*   Updated: 2017/01/03 11:49:49 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubc(char *src, char c)
{
	int		len;
	char	*dst;

	len = 0;
	if (!src)
		return (0);
	while (src[len] != c && src[len])
		len++;
	if (!(dst = ft_strsub(src, 0, (len))))
		return (0);
	return (dst);
}
