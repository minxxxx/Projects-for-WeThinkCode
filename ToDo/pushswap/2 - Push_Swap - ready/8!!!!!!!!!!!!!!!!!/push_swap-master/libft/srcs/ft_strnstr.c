/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:26:36 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/24 16:26:37 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i])
	{
		if (big[i] == *little)
		{
			j = 0;
			while (little[j] && little[j] == big[i + j])
				j++;
			if (little[j] == '\0' && (i + j) <= len)
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
