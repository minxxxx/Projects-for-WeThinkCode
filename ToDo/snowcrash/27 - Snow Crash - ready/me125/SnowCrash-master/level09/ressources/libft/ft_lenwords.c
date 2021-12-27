/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenwords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:53:38 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/01 05:06:14 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_lenwords(const char *s, char c, int word)
{
	int i;
	int j;

	i = 0;
	while (word != 0)
	{
		j = 0;
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
		}
		if (s[i] != c)
		{
			while (s[i] != c)
			{
				i++;
				j++;
			}
		}
		word--;
	}
	return (j);
}
