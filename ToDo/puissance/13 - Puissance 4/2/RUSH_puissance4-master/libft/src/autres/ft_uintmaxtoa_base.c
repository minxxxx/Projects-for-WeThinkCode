/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmaxtoa_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 11:52:44 by thou              #+#    #+#             */
/*   Updated: 2017/03/29 09:13:05 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_base(uintmax_t value, int base)
{
	int			i;

	i = 1;
	while (value / base != 0)
	{
		i++;
		value = value / base;
	}
	return (i);
}

char		*ft_uimtoa_base(uintmax_t value, int base, char x)
{
	int			i;
	uintmax_t	n;
	char		*c;
	char		*b;

	b = ((x == 'x') ? "0123456789abcdef" : "0123456789ABCDEF");
	c = (char*)malloc(sizeof(char) * (ft_nb_base(value, base) + 1));
	if (!c)
		return (NULL);
	i = ft_nb_base(value, base);
	c[i--] = 0;
	n = value;
	while (n / base != 0)
	{
		c[i--] = *(b + (n % base));
		n = n / base;
	}
	c[i] = *(b + (n % base));
	return (c);
}
