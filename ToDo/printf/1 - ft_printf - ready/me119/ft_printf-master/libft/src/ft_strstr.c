/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:03:06 by opodolia          #+#    #+#             */
/*   Updated: 2016/12/01 16:37:04 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;

	i = 0;
	if (*big == '\0' && *little == '\0')
		return ((char *)big);
	while (big[i] != '\0')
	{
		j = 0;
		while (big[i] == little[j] && big[i] != '\0' && little[j] != '\0')
		{
			i++;
			j++;
		}
		if (little[j] == '\0')
			return ((char *)big + i - j);
		else
			i -= j;
		i++;
	}
	return (0);
}
