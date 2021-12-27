/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 21:24:36 by tfleming          #+#    #+#             */
/*   Updated: 2014/11/07 11:39:54 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *first, const char *second)
{
	char	*end;

	end = ft_strchr(first, '\0');
	while (*second)
		*end++ = *second++;
	*end = '\0';
	return (first);
}
