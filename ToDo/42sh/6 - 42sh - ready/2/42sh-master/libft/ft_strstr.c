/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:32:10 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:32:12 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	inner;

	if (little[0] == '\0')
		return ((char *)big);
	while (*big)
	{
		inner = 0;
		while (big[inner] == little[inner])
		{
			if (little[inner + 1] == '\0')
				return ((char *)big);
			inner++;
		}
		big++;
	}
	return (NULL);
}
