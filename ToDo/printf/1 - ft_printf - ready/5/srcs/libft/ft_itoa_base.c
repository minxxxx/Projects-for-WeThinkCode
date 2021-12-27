/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 13:13:10 by thendric          #+#    #+#             */
/*   Updated: 2017/01/19 12:45:47 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_convert(long num, long temp, long len, int base)
{
	char	*numstr;
	char	*basenum;

	basenum = "0123456789abcdef";
	numstr = (char *)malloc(sizeof(char) * len + 1);
	if (!numstr)
		return (0);
	numstr[len] = '\0';
	while (num)
	{
		numstr[--len] = basenum[num % base];
		num /= base;
	}
	if (temp < 0)
	{
		if (base == 10)
			numstr[0] = '-';
		if (base == 8)
			numstr[0] = '3';
	}
	return (numstr);
}

char		*ft_itoa_base(int value, int base)
{
	long	n;
	long	temp;
	long	len;
	char	*numstr;

	len = 0;
	temp = value;
	n = value;
	if (value < 0)
	{
		if (base == 10 || base == 8)
			len++;
		n = n * -1;
	}
	if (!value)
		return ("0");
	while (value)
	{
		value /= base;
		len++;
	}
	numstr = ft_convert(n, temp, len, base);
	return (numstr);
}
