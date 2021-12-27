/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:11:10 by wide-aze          #+#    #+#             */
/*   Updated: 2014/12/31 09:04:38 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	char	src_is_finished;

	i = 0;
	src_is_finished = 0;
	while (i < n)
	{
		if (!src_is_finished && !src[i])
			src_is_finished = 1;
		if (!src_is_finished)
			dst[i] = src[i];
		else
			dst[i] = '\0';
		i++;
	}
	return (dst);
}
