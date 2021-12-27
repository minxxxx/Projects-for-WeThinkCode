/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:52:20 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/01 05:04:32 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_countwords(const char *s, char c)
{
	int	i;
	int	cp;

	i = 0;
	cp = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			cp++;
			while (s[i] != c && s[i] != 0)
				i++;
		}
		if (s[i] != 0)
			i++;
	}
	return (cp);
}
