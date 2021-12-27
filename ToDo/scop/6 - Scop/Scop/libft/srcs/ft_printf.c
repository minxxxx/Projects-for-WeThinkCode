/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 13:32:42 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/04 17:09:42 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_type(const char *format, int i, va_list ap)
{
	if (format[i] == 's')
		return (ft_printf_str(va_arg(ap, char *)));
	else if (format[i] == 'd' || format[i] == 'i')
		return (ft_printf_nbr(va_arg(ap, int)));
	else if (format[i] == 'c')
		return (ft_printf_char(va_arg(ap, int)));
	else if (format[i] == 'u')
		return (ft_printf_unbr(va_arg(ap, unsigned int)));
	else if (format[i] == 'Z')
		return (ft_printf_char('Z'));
	else if (format[i] == 'o')
		return (ft_printf_octal(va_arg(ap, int)));
	else if (format[i] == 'x' || format[i] == 'X' || format[i] == 'p')
		return (ft_print_hex(format, i, ap));
	else if (format[i] == 'l')
		return (ft_printf_long(format, i, ap));
	else if (format[i] == 'f')
		return (ft_printf_nbr_lf(va_arg(ap, double)));
	else if (format[i] == ' ')
		return (0);
	else
		return (ft_printf_char(format[i]));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				count += ft_printf_char(format[i]);
			else
				count += ft_printf_type(format, i, ap);
		}
		else if (format[i] != '%')
		{
			ft_printf_char(format[i]);
			count++;
		}
		i++;
	}
	return (count);
}
