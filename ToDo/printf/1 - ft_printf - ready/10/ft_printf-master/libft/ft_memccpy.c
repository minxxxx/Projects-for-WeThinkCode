/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:57:59 by tfleming          #+#    #+#             */
/*   Updated: 2014/11/08 19:12:48 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dest, const void *source
							, int stopper, size_t len)
{
	size_t			i;
	char			curr;

	i = 0;
	while (i < len)
	{
		curr = ((char*)source)[i];
		((char*)dest)[i] = curr;
		i++;
		if (curr == stopper)
			return ((char*)dest + i);
	}
	return (NULL);
}
