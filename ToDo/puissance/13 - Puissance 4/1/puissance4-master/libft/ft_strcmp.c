/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:59:56 by telain            #+#    #+#             */
/*   Updated: 2015/12/02 15:39:32 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *str, const char *str2)
{
	int		i;

	i = 0;
	while (str[i] || str2[i])
	{
		if (str[i] != str2[i])
			return ((unsigned char)str[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
