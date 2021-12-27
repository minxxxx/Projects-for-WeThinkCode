/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:14:33 by opodolia          #+#    #+#             */
/*   Updated: 2016/12/12 20:51:27 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (big[i] == little[j] && big[i] != '\0' && little[j] != '\0')
		{
			i++;
			j++;
		}
		if (little[j] == '\0' && i <= len)
			return ((char *)big + i - j);
		else
			i -= j;
		i++;
	}
	return (0);
}
