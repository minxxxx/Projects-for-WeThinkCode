/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_ul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 09:55:17 by apakhomo          #+#    #+#             */
/*   Updated: 2018/01/27 09:55:17 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

static int		ft_pow(int x, unsigned int y)
{
	int temp;

	if (y == 0)
		return (1);
	temp = ft_pow(x, y / 2);
	if (y % 2 == 0)
		return (temp * temp);
	else
		return (x * temp * temp);
}

unsigned long	ft_hex_to_ul(char *str)
{
	int				length;
	unsigned long	decnum;
	int				i;

	length = 0;
	decnum = 0;
	i = 0;
	while (str[length] && str[length] != 32)
		length++;
	while (i < length)
	{
		if (*str >= 48 && *str <= 57)
			decnum += (((int)(*str)) - 48) * ft_pow(16, length - i - 1);
		else if ((*str >= 65 && *str <= 70))
			decnum += (((int)(*str)) - 55) * ft_pow(16, length - i - 1);
		else if (*str >= 97 && *str <= 102)
			decnum += (((int)(*str)) - 87) * ft_pow(16, length - i - 1);
		i++;
		str++;
	}
	return (decnum);
}
