/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemiy <artemiy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 00:29:29 by artemiy           #+#    #+#             */
/*   Updated: 2019/01/04 00:44:09 by artemiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_num_len(unsigned long long n, int base)
{
	int len;

	len = 0;
	while (n > 0)
	{
		n /= base;
		len += 1;
	}
	return (len);
}

char 	*ft_ullitoa_base(unsigned long long num, const char *sym, int base)
{
	char	*str;
	int		len;

	len = ft_num_len(num, base);
	if (num == 0)
		len = 1;
	if ((str = ft_strnew((size_t)len)) == NULL)
		return (NULL);
	while (len - 1 >= 0)
	{
		str[len - 1] = sym[num % base];
		num /= base;
		len--;
	}
	return (str);
}
