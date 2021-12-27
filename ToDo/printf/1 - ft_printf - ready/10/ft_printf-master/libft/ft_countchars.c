/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:20:55 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 16:03:30 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_countchars(char const *haystack, char needle
										, size_t length)
{
	size_t			count;
	size_t			i;

	count = 0;
	i = 0;
	while (i < length)
	{
		if (haystack[i] == needle)
			count++;
		i++;
	}
	return (count);
}
