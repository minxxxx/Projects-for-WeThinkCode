/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 15:33:24 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 15:57:53 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strcount(char const *haystack, char const needle)
{
	size_t			count;

	while (haystack)
	{
		if (*haystack == needle)
			count++;
		haystack++;
	}
	return (count);
}
