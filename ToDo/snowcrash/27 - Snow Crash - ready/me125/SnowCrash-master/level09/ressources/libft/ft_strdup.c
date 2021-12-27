/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:17:51 by dgalide           #+#    #+#             */
/*   Updated: 2016/03/04 21:52:06 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(char *str)
{
	int		i;
	char	*dup;

	i = 0;
	if (!str)
		return (NULL);
	dup = (char *)malloc(ft_strlen(str) + 1);
	if (dup == NULL)
		return (NULL);
	else
	{
		while (str[i])
		{
			dup[i] = str[i];
			i++;
		}
		dup[i] = '\0';
		return (dup);
	}
}
