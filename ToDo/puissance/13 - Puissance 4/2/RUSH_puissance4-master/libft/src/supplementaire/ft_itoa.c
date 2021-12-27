/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:16:44 by thou              #+#    #+#             */
/*   Updated: 2016/11/18 15:36:48 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int n)
{
	int i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		i++;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*c;
	int		i;

	i = len(n);
	c = (char*)malloc(sizeof(char) * (i + 1));
	if (!c)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		c[0] = '-';
		n = -n;
	}
	c[i--] = 0;
	if (n == 0)
		c[i] = '0';
	while (n)
	{
		c[i--] = n % 10 + 48;
		n = n / 10;
	}
	return (c);
}
