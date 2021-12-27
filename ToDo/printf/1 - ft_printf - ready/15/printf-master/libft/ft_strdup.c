/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:05:55 by fkuhn             #+#    #+#             */
/*   Updated: 2018/11/29 16:10:32 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*pt;

	i = 0;
	len = ft_strlen(s1);
	pt = malloc(sizeof(char) * (len + 1));
	if (!pt)
		return (NULL);
	while (s1[i])
	{
		pt[i] = s1[i];
		++i;
	}
	pt[i] = '\0';
	return (pt);
}
