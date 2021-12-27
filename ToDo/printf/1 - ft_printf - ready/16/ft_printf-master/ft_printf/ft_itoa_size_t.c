/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_size_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:23:30 by dkotenko          #+#    #+#             */
/*   Updated: 2018/01/18 13:23:32 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*str_ret_long(size_t num, int i, char *str)
{
	while (num)
	{
		str[i--] = 48 + (num % 10);
		num = num / 10;
	}
	return (str);
}

char			*ft_itoa_size_t(size_t n)
{
	int							i;
	size_t						num;
	char						*str;

	i = 0;
	num = n;
	if (num == 0)
		return (ft_strdup("0"));
	while (n)
	{
		n = n / 10;
		i++;
	}
	str = (char*)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	return (str_ret_long(num, i, str));
}
