/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 10:52:32 by sasiedu           #+#    #+#             */
/*   Updated: 2016/05/25 15:42:09 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_do_zero1(va_list param, int num)
{
	int		len;
	int		store;

	len = 1;
	store = ft_retint(param);
	len = ft_count_UInum(store, 10);
	while (num > len)
	{
		ft_putchar('0');
		num--;
	}
	ft_putnbr(store);
	return (0);
}

int		ft_do_zero2(va_list param, char *str, int num)
{
	int					len;
	char				*str1;

	len = 1;
	str1 = ft_retstr(param, str);
	len = ft_strlen(str1);
	while (num > len)
	{
		ft_putchar('0');
		num--;
	}
	ft_putstr(str1);
	return (0);
}

int		ft_zero(va_list param, char *str)
{
	int			i;
	size_t		num;
	char		temp[10];

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	num = ft_atoi(temp);
	if (str[i] == 's' || str[i] == 'S' || str[i] == 'c' || str[i] == 'C')
		exit(-1);
	if (str[i] == 'i' || str[i] == 'd')
		ft_do_zero1(param, num);
	else
		ft_do_zero2(param, &str[i], num);
	return (2 + i);
}
