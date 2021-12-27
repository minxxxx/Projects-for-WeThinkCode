/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 15:16:33 by sasiedu           #+#    #+#             */
/*   Updated: 2016/05/25 16:56:26 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int			ft_padding(va_list param, char *str)
{
	int		i;
	int		count;
	char	temp[10];

	i = 0;
	while (ft_isdigit(str[i]) == 1)
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	count = ft_atoi(temp);
	if (str[i] != 'd' && str[i] != 'i' && str[0] != 'c' && str[0] != 'C')
		return (1 + i + ft_padding1(param, &str[i], count, NULL));
	else if (str[i] != 'c' && str[i] != 'C')
		return (1 + i + ft_padding2(param, count));
	while (count > 1)
	{
		ft_putchar(' ');
		count--;
	}
	ft_putchar(va_arg(param, int));
	return (2 + i);
}

int			ft_padding2(va_list param, int count)
{
	int		len;
	int		num;

	len = 1;
	num = va_arg(param, int);
	len = ft_count_UInum(num, 10);
	while (count > len)
	{
		ft_putchar(' ');
		count--;
	}
	ft_putnbr(num);
	return (0);
}

int			ft_padding1(va_list param, char *str, int count, char *str1)
{
	int		len;

	str1 = ft_retstr(param, str);
	len = ft_strlen(str1);
	while (count > len)
	{
		ft_putchar(' ');
		count--;
	}
	ft_putstr(str1);
	return (0);
}
