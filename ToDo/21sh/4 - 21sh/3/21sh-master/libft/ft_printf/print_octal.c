/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:03:36 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/12 17:51:40 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_octal(unsigned long long nb, t_arg *arg)
{
	int	nb_char;

	nb_char = count_char_usigned_decimal_base(nb, 8);
	if (arg->minus)
		minus_octal(nb, nb_char, arg);
	else if (arg->zero)
		zero_octal(nb, nb_char, arg);
	else
	{
		if (nb == 0 && arg->precision == 0)
			arg->width++;
		if (arg->sharp && arg->precision == -1)
			arg->width--;
		no_flag_octal(nb, nb_char, arg);
	}
}

void	minus_octal(unsigned long long nb, int nb_char, t_arg *arg)
{
	if (arg->precision > nb_char)
	{
		ft_putnchar('0', arg->precision - nb_char);
		g_bytes += arg->precision - nb_char;
	}
	else if (arg->sharp && ++g_bytes && --arg->width)
		ft_putchar('0');
	if (nb == 0 && arg->precision == 0 && ++g_bytes)
		ft_putchar(' ');
	else if (g_bytes += nb_char)
		ft_put_ullong_base(nb, 8);
	if (arg->width > arg->precision && arg->width > nb_char)
	{
		if (arg->precision > nb_char)
		{
			ft_putnchar(' ', arg->width - arg->precision);
			g_bytes += arg->width - arg->precision;
		}
		else if (nb_char >= arg->precision)
		{
			ft_putnchar(' ', arg->width - nb_char);
			g_bytes += arg->width - nb_char;
		}
	}
}

void	zero_octal(unsigned long long nb, int nb_char, t_arg *arg)
{
	if (arg->width > nb_char && arg->precision == -1)
	{
		ft_putnchar('0', arg->width - nb_char);
		ft_put_ullong_base(nb, 8);
		g_bytes += arg->width;
	}
	else
	{
		if (nb == 0 && arg->precision == 0)
			arg->width++;
		no_flag_octal(nb, nb_char, arg);
	}
}

void	no_flag_octal(unsigned long long nb, int nb_char, t_arg *arg)
{
	if (arg->width > arg->precision && arg->precision > nb_char)
	{
		ft_putnchar(' ', arg->width - arg->precision);
		g_bytes += arg->width - arg->precision;
	}
	else if (arg->width > nb_char && nb_char >= arg->precision)
	{
		ft_putnchar(' ', arg->width - nb_char);
		g_bytes += arg->width - nb_char;
	}
	if (arg->precision > nb_char)
	{
		ft_putnchar('0', arg->precision - nb_char);
		g_bytes += arg->precision - nb_char;
	}
	else if ((arg->sharp && nb > 0 && ++g_bytes) ||
			(arg->sharp && arg->precision++ && ++g_bytes))
		ft_putchar('0');
	if (!(nb == 0 && arg->precision == 0))
	{
		ft_put_ullong_base(nb, 8);
		g_bytes += nb_char;
	}
}
