/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 15:30:47 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/26 17:08:04 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strchr_last(const char *haystack, int needle)
{
	char			*end;

	end = ft_strchr(haystack, '\0');
	while (end >= haystack)
	{
		if (*end == needle)
			return ((char*)end);
		end--;
	}
	return (NULL);
}
