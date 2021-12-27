/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 15:33:53 by dgalide           #+#    #+#             */
/*   Updated: 2016/04/01 15:33:54 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t		ft_nbrlen(unsigned long long n, int base)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char				*ft_unsigned_itoa(unsigned long long n, int base)
{
	char				*str;
	size_t				len;

	len = ft_nbrlen(n, base) - 1;
	str = ft_strnew(len + 1);
	if (!str)
		return (NULL);
	if (n == 0)
		str[len] = '0';
	while (n)
	{
		str[len] = (base > 10 && n % base > 9) ?
			(n % base) + ('a' - 10) : (n % base) + 48;
		n /= base;
		len--;
	}
	return (str);
}
