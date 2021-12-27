/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 13:34:15 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/04 17:10:57 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf_hex(unsigned int n)
{
	if (n >= 16)
		return (ft_printf_hex(n / 16) + ft_printf_hex(n % 16));
	else
		return (ft_printf_char(HEX[n]));
}

int		ft_print_hex(const char *format, int i, va_list ap)
{
	if (format[i] == 'x')
		return (ft_printf_hex(va_arg(ap, unsigned int)));
	if (format[i] == 'X')
		return (ft_printf_hexm(va_arg(ap, unsigned int)));
	if (format[i] == 'p')
		return (ft_printf_ptr(va_arg(ap, void *)));
	return (1);
}

int		ft_printf_hexm(unsigned int n)
{
	if (n >= 16)
		return (ft_printf_hexm(n / 16) + ft_printf_hexm(n % 16));
	else
		return (ft_printf_char(ft_toupper(HEX[n])));
}

int		ft_printf_hexa(unsigned long n)
{
	if (n >= 16)
		return (ft_printf_hexa(n / 16) + ft_printf_hexa(n % 16));
	else
		return (ft_printf_char(HEX[n]));
}

int		ft_printf_ptr(void *n)
{
	int	i;

	if (n == NULL)
		return (i = ft_printf_str("0x0"));
	i = ft_printf_str("0x");
	return (ft_printf_hexa((unsigned long)n) + i);
}
