/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:58:17 by thou              #+#    #+#             */
/*   Updated: 2016/11/14 12:35:22 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	size_t	i;
	size_t	j;

	b = (char*)big;
	l = (char*)little;
	if (!*l)
		return (b);
	i = 0;
	while (b[i])
	{
		j = 0;
		while (b[i + j] == l[j] && i + j < len)
		{
			if (l[++j] == 0)
				return (b + i);
		}
		i++;
	}
	return (NULL);
}
