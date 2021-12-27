/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <jmontija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 15:59:46 by jtranchi          #+#    #+#             */
/*   Updated: 2016/11/12 21:56:04 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	int		ft_strstrcheck(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

char			*ft_strstr(const char *s1, const char *s2)
{
	int i;

	i = 0;
	if (*s2)
	{
		while (s1[i])
		{
			if (s1[i] == *s2)
				if (ft_strstrcheck((s1 + i), s2))
					return ((char *)s1 + i);
			i++;
		}
		return ((void *)NULL);
	}
	else
		return ((char *)s1);
}
