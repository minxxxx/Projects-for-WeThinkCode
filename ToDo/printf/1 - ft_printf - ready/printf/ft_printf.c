/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 13:59:17 by sasiedu           #+#    #+#             */
/*   Updated: 2016/05/25 16:56:41 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_printf(char *restrict format, ...)
{
	size_t		i;
	va_list		param;

	i = 0;
	va_start(param, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && ft_compare(&format[i + 1]) == 1)
		{
			do_convert(param, &format[i + 1]);
			i = i + 1;
		}
		else if (format[i] == '%' && ft_compare(&format[i + 1]) == 2)
			i = i + do_flags(param, &format[i + 1]);
		else if (format[i] == '%' && ft_isdigit(format[i + 1]) == 1)
			i = i + ft_padding(param, &format[i + 1]);
		else
			ft_putchar(format[i]);
		i++;
	}
	return (0);
}
