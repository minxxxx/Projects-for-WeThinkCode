/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:10:50 by tfleming          #+#    #+#             */
/*   Updated: 2014/11/08 12:10:10 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dest, const char *src, size_t max)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < max)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < max)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
