/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 12:05:47 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/12 17:52:30 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(va_list ap, t_arg *arg)
{
	char	*s;
	int		nb_char;

	if (!(s = va_arg(ap, char *)))
		s = "(null)";
	nb_char = ft_strlen(s);
	if (arg->precision > -1 && arg->precision < nb_char)
		flags_on_string(s, arg);
	else if (arg->width > nb_char && arg->minus)
	{
		ft_putstr(s);
		ft_putnchar(' ', arg->width - nb_char);
		g_bytes += arg->width;
	}
	else if (arg->width > nb_char)
	{
		arg->zero ? ft_putnchar('0', arg->width - nb_char) :
		ft_putnchar(' ', arg->width - nb_char);
		ft_putstr(s);
		g_bytes += arg->width;
	}
	else if (g_bytes += nb_char)
		ft_putstr(s);
}

void	flags_on_string(char *s, t_arg *arg)
{
	int	n;

	n = 0;
	if (arg->width > arg->precision && arg->minus)
	{
		n = arg->width - arg->precision;
		ft_putnstr(s, arg->precision);
		ft_putnchar(' ', n);
	}
	else if (arg->width > arg->precision)
	{
		n = arg->width - arg->precision;
		arg->zero ? ft_putnchar('0', n) : ft_putnchar(' ', n);
		ft_putnstr(s, arg->precision);
	}
	else
		ft_putnstr(s, arg->precision);
	g_bytes += n + arg->precision;
}
