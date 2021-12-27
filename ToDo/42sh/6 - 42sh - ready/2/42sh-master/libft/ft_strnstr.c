/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:31:22 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:31:23 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	i;

	if (*small == '\0')
		return ((char *)big);
	i = ft_strlen(small);
	while (*big != '\0' && len-- >= i)
	{
		if (*big == *small && ft_memcmp(big, small, i) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
