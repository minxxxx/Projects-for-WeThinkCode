/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:08:22 by tfleming          #+#    #+#             */
/*   Updated: 2014/11/08 23:31:52 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memset(void *destination, int int_value, size_t len)
{
	size_t			i;
	unsigned char	*location;
	unsigned char	value;

	value = (unsigned char)int_value;
	location = (unsigned char*)destination;
	i = 0;
	while (i < len)
	{
		location[i] = value;
		i++;
	}
	return (destination);
}
