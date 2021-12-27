/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 13:13:10 by thendric          #+#    #+#             */
/*   Updated: 2016/12/28 13:13:12 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		g_neg;

static char	*ft_convert(long value, ssize_t size, size_t temp, int base)
{
	char	*numstr;
	char	*basenum;

	basenum = ft_strdup("0123456789abcdef");
	if (!(numstr = ft_strnew(size)))
		return (0);
	numstr[size--] = '\0';
	while (*numstr)
		numstr++;
	if (g_neg == 1)
		temp = value * -1;
	else
		temp = value;
	while (size >= 0)
	{
		numstr[size] = basenum[temp % base];
		size--;
		temp /= base;
	}
	if (g_neg == 1)
		numstr[0] = '-';
	if (g_neg == 2)
		numstr[0] = '3';
	return (numstr);
}

char		*ft_itoa_base_long(long value, int base)
{
	ssize_t	size;
	size_t	temp;
	char	*numstr;

	g_neg = 0;
	size = 1;
	temp = value;
	if (base == 8 && value < 0)
		g_neg = 2;
	if (base == 10 && value < 0)
	{
		temp *= -1;
		g_neg = 1;
		size++;
	}
	if (base == 16 && value == -2147483648)
		temp *= -1;
	else if (base != 10 && value < 0)
		temp -= -2147483648;
	while ((temp /= base) > 0)
		size++;
	numstr = ft_convert(value, size, temp, base);
	return (numstr);
}
