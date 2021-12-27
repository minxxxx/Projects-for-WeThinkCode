/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 07:46:50 by pbondoer          #+#    #+#             */
/*   Updated: 2016/12/24 07:56:05 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnumber(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
		{
			if (i == 0)
			{
				i++;
				continue ;
			}
			else
				return (0);
		}
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
