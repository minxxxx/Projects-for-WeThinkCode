/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:31:00 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/01 05:13:07 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	int		i;
	char	*cpy;

	if (s)
	{
		i = 0;
		cpy = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (!cpy)
			return (NULL);
		while (s[i])
		{
			cpy[i] = (*f)(s[i]);
			i++;
		}
		cpy[i] = '\0';
		return (cpy);
	}
	else
		return (NULL);
}
