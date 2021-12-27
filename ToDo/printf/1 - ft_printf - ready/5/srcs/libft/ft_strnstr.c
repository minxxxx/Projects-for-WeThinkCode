/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <thendric@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 20:17:39 by thendric          #+#    #+#             */
/*   Updated: 2016/11/06 23:39:20 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*b;
	char	*l;

	i = 0;
	b = (char *)big;
	l = (char *)little;
	if (!*little)
		return ((char *)big);
	while (b[i] && i < len)
	{
		j = 0;
		while ((b[i + j] == l[j]) && (i + j < len))
		{
			j++;
			if (!l[j])
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
