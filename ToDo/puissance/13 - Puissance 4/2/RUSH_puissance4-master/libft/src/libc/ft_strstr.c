/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:15:51 by thou              #+#    #+#             */
/*   Updated: 2016/11/14 16:59:55 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*b;
	char	*l;
	int		i;

	b = (char*)big;
	l = (char*)little;
	if (!*l)
		return (b);
	while (*b)
	{
		i = 0;
		while (b[i] == l[i] && b[i] && l[i])
		{
			i++;
			if (l[i] == 0)
				return (b);
		}
		b++;
	}
	return (NULL);
}
