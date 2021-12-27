/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmaxtoa_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 08:54:30 by thou              #+#    #+#             */
/*   Updated: 2017/03/29 12:37:33 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_base(intmax_t value, int base)
{
	int			i;

	i = 1;
	if (base == 10 && value < 0)
		i++;
	while (value / base != 0)
	{
		i++;
		value = value / base;
	}
	return (i);
}

char		*ft_intmaxtoa_base(intmax_t value, int base, char x)
{
	intmax_t	i;
	intmax_t	n;
	char		*c;
	char		*b;

	b = (ft_isupper(x)) ? "0123456789ABCDEF" : "0123456789abcdef";
	c = (char*)malloc(sizeof(char) * (ft_nb_base(value, base) + 1));
	if (!c)
		return (NULL);
	i = ft_nb_base(value, base);
	c[i--] = 0;
	if (value == INTMAX_MIN)
		return (ft_strcpy(c, "-9223372036854775808"));
	n = (value < 0) ? -value : value;
	if (base == 10 && value < 0)
		c[0] = '-';
	while (n / base != 0)
	{
		c[i--] = *(b + (n % base));
		n = n / base;
	}
	c[i] = *(b + (n % base));
	return (c);
}
