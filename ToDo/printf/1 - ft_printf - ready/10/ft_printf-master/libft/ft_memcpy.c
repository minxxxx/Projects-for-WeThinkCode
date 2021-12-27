/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:54:44 by tfleming          #+#    #+#             */
/*   Updated: 2014/11/07 15:01:38 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dest, const void *source, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		((char*)dest)[i] = ((char*)source)[i];
		i++;
	}
	return (dest);
}
