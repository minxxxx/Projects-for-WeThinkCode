/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:20:55 by tfleming          #+#    #+#             */
/*   Updated: 2014/11/07 11:29:06 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strchr(const char *haystack, int needle)
{
	while (*haystack && *haystack != needle)
		haystack++;
	if (*haystack == needle)
		return ((char*)haystack);
	return (NULL);
}
