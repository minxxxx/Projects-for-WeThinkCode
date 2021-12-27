/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 21:35:06 by tfleming          #+#    #+#             */
/*   Updated: 2014/11/14 12:10:14 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *first, const char *second, size_t len)
{
	char	*end;
	size_t	i;

	end = ft_strchr(first, '\0');
	i = 0;
	while (second[i] && i < len)
	{
		end[i] = second[i];
		i++;
	}
	end[i] = '\0';
	return (first);
}
