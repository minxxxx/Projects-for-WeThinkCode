/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:01:07 by jtranchi          #+#    #+#             */
/*   Updated: 2015/12/08 11:18:40 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(ft_strlen(s1) + 1);
	if (dup == NULL)
		return (NULL);
	else
	{
		while (s1[i])
		{
			dup[i] = s1[i];
			i++;
		}
		dup[i] = '\0';
		return (dup);
	}
}
