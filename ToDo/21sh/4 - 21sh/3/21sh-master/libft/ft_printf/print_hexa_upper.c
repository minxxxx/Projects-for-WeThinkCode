/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:03:36 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/12 17:51:14 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hexa_upper(unsigned long long nb, int nb_char, t_arg *arg)
{
	if (arg->sharp && nb != 0)
	{
		g_bytes += 2;
		arg->width -= 2;
		if (arg->minus || arg->zero)
			ft_putstr("0X");
	}
	if (arg->minus)
		minus_hexa_upper(nb, nb_char, arg);
	else if (arg->zero)
		zero_hexa_upper(nb, nb_char, arg);
	else
	{
		if (nb == 0 && arg->precision == 0)
			arg->width++;
		no_flag_hexa_upper(nb, nb_char, arg);
	}
}

void	minus_hexa_upper(unsigned long long nb, int nb_char, t_arg *arg)
{
	if (arg->precision > nb_char)
	{
		ft_putnchar('0', arg->precision - nb_char);
		g_bytes += arg->precision - nb_char;
	}
	if (nb == 0 && arg->precision == 0 && ++g_bytes)
		ft_putchar(' ');
	else if (g_bytes += nb_char)
		ft_put_ullong_base_upper(nb, 16);
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

void	zero_hexa_upper(unsigned long long nb, int nb_char, t_arg *arg)
{
	if (arg->width > nb_char && arg->precision == -1)
	{
		ft_putnchar('0', arg->width - nb_char);
		ft_put_ullong_base_upper(nb, 16);
		g_bytes += arg->width;
	}
	else
	{
		if (nb == 0 && arg->precision == 0)
			arg->width++;
		no_flag_hexa_upper(nb, nb_char, arg);
	}
}

void	no_flag_hexa_upper(unsigned long long nb, int nb_char, t_arg *arg)
{
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
	if (!arg->zero && arg->sharp && nb != 0)
		ft_putstr("0X");
	if (arg->precision > nb_char)
	{
		ft_putnchar('0', arg->precision - nb_char);
		g_bytes += arg->precision - nb_char;
	}
	if (!(nb == 0 && arg->precision == 0))
	{
		ft_put_ullong_base_upper(nb, 16);
		g_bytes += nb_char;
	}
}
