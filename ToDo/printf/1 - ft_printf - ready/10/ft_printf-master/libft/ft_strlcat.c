/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:46:14 by tfleming          #+#    #+#             */
/*   Updated: 2014/11/09 20:48:32 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *first, const char *second, size_t size)
{
	size_t		end;
	size_t		i;

	if (size == 0)
		return (ft_strlen(second));
	end = ft_strlen(first);
	if (end > size - 1)
		return (size + ft_strlen(second));
	i = 0;
	while (second[i] && end + i < size - 1)
	{
		first[i + end] = second[i];
		i++;
	}
	first[i + end] = '\0';
	return (end + ft_strlen(second));
}
