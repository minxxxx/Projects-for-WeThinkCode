/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:55:55 by juspende          #+#    #+#             */
/*   Updated: 2017/12/05 16:31:06 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../include/ft_printf.h"
#include <string.h>

int			ft_uintlen(uintmax_t n, int base)
{
	int			i;

	i = 1;
	while (n /= base)
		++i;
	return (i);
}

char		*ft_itoa(uintmax_t n, int base)
{
	int			i;
	char		*str;

	if (base > 30)
		return (NULL);
	i = ft_uintlen(n, base);
	if (!(str = malloc((i + 1) * sizeof(char))))
		return (NULL);
	i = ft_uintstr(str, n, base);
	str[i] = '\0';
	return (str);
}

int			ft_uintstr(char *dst, uintmax_t n, int base)
{
	int			i;
	static char	digits[31] = "0123456789abcdefghijklmnopqrs";

	if (base > 30)
		return (0);
	if (n == 0)
		return ((int)(((*dst = '0') & 0) + 1));
	i = int_len(n);
	dst += i - 1;
	while (n)
	{
		*dst-- = digits[n % base];
		n /= base;
	}
	return (i);
}
