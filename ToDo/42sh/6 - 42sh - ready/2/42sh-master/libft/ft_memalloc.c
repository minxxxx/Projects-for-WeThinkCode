/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:18:15 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:18:18 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Simplifies the process of using malloc in a function by auto using malloc
 ** within this function to any input when used.
*/

void	*ft_memalloc(size_t size)
{
	unsigned char	*len;

	len = (unsigned char*)malloc(sizeof(char) * size);
	if (len == NULL)
		return (NULL);
	return (ft_memset(len, 0, size));
}
