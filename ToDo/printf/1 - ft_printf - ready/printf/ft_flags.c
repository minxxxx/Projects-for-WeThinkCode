/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 12:28:26 by sasiedu           #+#    #+#             */
/*   Updated: 2016/06/05 11:41:42 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int			do_flags(va_list param, char *str)
{
	if (str[0] == '+')
		return (ft_plus(param, str));
	if (str[0] == '-')
		return (ft_minus(param, &str[1]));
	if (str[0] == ' ')
		return (ft_space(param, &str[1]));
	if (str[0] == '#')
		return (ft_tag(param, str));
	if (str[0] == '0')
		return (ft_zero(param, &str[1]));
	return (2);
}

int			ft_tag(va_list param, char *str)
{
	int			len;
	int			i;

	len = 0;
	i = 1;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != 'o' && str[i] != 'x' && str[i] != 'O' && str[i] != 'X')
		exit(-1);
	if (str[i] == 'o')
	{
		ft_putchar('0');
		len = do_convert(param, &str[i]);
	}
	if (str[i] == 'x')
	{
		ft_putstr("0x");
		len = do_convert(param, &str[i]);
	}
	if (str[i] == 'X')
	{
		ft_putstr("0X");
		len = do_convert(param, &str[i]);
	}
	return (1 + i);
}

int			ft_plus(va_list param, char *str)
{
	int		num;

	if (str[0] == '+' && (str[1] == 'd' || str[1] == 'i'))
	{
		if ((num = va_arg(param, int)) > 0)
		{
			ft_putchar('+');
			ft_putnbr(num);
		}
		else
			ft_putnbr(num);
	}
	return (2);
}

int			ft_minus(va_list param, char *str)
{
	int		i;
	size_t	num;
	size_t	len;
	char	temp[10];

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	num = ft_atoi(temp);
	len = do_convert(param, &str[i]);
	while (num > len)
	{
		ft_putchar(' ');
		num--;
	}
	return (2 + i);
}

int			ft_space(va_list param, char *str)
{
	int		i;
	int		num;
	int		src;
	char	temp[10];

	i = 0;
	if (str[0] == '+')
		return (1 + ft_plus(param, str));
	src = va_arg(param, int);
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp[i] = str[i];
		i++;
	}
	if (str[i] != 'i' && str[i] != 'd')
		exit(-1);
	num = ft_atoi(temp);
	if (src > 0)
		ft_putchar(' ');
	ft_putnbr(src);
	return (2 + i);
}
