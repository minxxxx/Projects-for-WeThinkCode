/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 11:16:58 by sasiedu           #+#    #+#             */
/*   Updated: 2016/06/05 13:49:27 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_compare(char *str)
{
	if (str[0] == 'd' || str[0] == 'i' || str[0] == 'o' || str[0] == 'u')
		return (1);
	if (str[0] == 's' || str[0] == 'c' || str[0] == 'x' || str[0] == 'U')
		return (1);
	if (str[0] == 'D' || str[0] == 'X' || str[0] == 'C' || str[0] == 'O')
		return (1);
	if (str[0] == 'p' || str[0] == 'S' || str[0] == '%')
		return (1);
	if (str[0] == '#' || str[0] == '0' || str[0] == '-' || str[0] == '+')
		return (2);
	if (str[0] == ' ')
		return (2);
	return (0);
}

int		do_convert(va_list param, char *str)
{
	if (str[0] == 'd' || str[0] == 'i' || str[0] == 'c' || str[0] == 'C')
		return (ft_convert(param, str));
	if (str[0] == 'x' || str[0] == 'X' || str[0] == 'o' || str[0] == 'O')
		return (ft_convert(param, str));
	if (str[0] == 'u' || str[0] == 'U' || str[0] == 'D' || str[0] == 's')
		return (ft_convert(param, str));
	if (str[0] == 'p')
		return (ft_convert_ptr(param));
	if (str[0] == '%')
	{
		ft_putchar('%');
		return (1);
	}
	return (0);
}

int		ft_convert(va_list param, char *str)
{
	int		num;
	int		len;
	char	*str1;

	len = 1;
	str1 = NULL;
	if (str[0] == 'i' || str[0] == 'd')
		num = ft_retint(param);
	else if (str[0] == 'c' || str[0] == 'C')
		num = va_arg(param, int);
	else
		str1 = ft_retstr(param, str);
	if (!str1 && (str[0] != 'c' || str[0] != 'C'))
		len = ft_count_UInum(num, 10);
	else if (str1)
		len = ft_strlen(str1);
	if (!str1 && (str[0] == 'd' || str[0] == 'i'))
		ft_putnbr(num);
	else if (str1)
		ft_putstr(str1);
	else
		write(1, &num, 1);
	return (len);
}

int		ft_convert_ptr(va_list param)
{
	int		len;
	void	*ptr;

	ptr = va_arg(param, void *);
	len = ft_strlen(ptr);
	ft_print_addr(ptr);
	return (len);
}
