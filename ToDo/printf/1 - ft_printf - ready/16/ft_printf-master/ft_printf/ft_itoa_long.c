/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:30:16 by dkotenko          #+#    #+#             */
/*   Updated: 2018/01/12 13:30:17 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*str_ret_long(unsigned int long long num, int i, char *str)
{
	while (num)
	{
		str[i--] = 48 + (num % 10);
		num = num / 10;
	}
	return (str);
}

char			*ft_itoa_long(int long long n)
{
	int							i;
	unsigned int long long		num;
	char						*str;

	i = 0;
	num = (unsigned int long long)n;
	if (num == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		num = n * -1;
		i = 1;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	str = (char*)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[0] = '-';
	str[i--] = '\0';
	return (str_ret_long(num, i, str));
}
