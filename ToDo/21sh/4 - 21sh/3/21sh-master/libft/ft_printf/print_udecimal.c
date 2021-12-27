/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_udecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 10:03:23 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/12 17:52:44 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_usigned_decimal(unsigned long long nb, t_arg *arg)
{
	int	nb_char;

	nb_char = count_char_usigned_decimal_base(nb, 10);
	if (arg->minus)
		minus_udecimal(nb, nb_char, arg);
	else if (arg->zero)
		zero_udecimal(nb, nb_char, arg);
	else
		no_flag_udecimal(nb, nb_char, arg);
}

void	minus_udecimal(unsigned long long nb, int nb_char, t_arg *arg)
{
	if (arg->precision > nb_char)
	{
		ft_putnchar('0', arg->precision - nb_char);
		g_bytes += arg->precision - nb_char;
	}
	if (nb == 0 && arg->precision == 0 && ++g_bytes)
		ft_putchar(' ');
	else
	{
		ft_put_ullong_base(nb, 10);
		g_bytes += nb_char;
	}
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

void	zero_udecimal(unsigned long long nb, int nb_char, t_arg *arg)
{
	if (arg->width > nb_char && arg->precision == -1)
	{
		ft_putnchar('0', arg->width - nb_char);
		ft_put_ullong_base(nb, 10);
		g_bytes += arg->width;
	}
	else
		no_flag_udecimal(nb, nb_char, arg);
}

void	no_flag_udecimal(unsigned long long nb, int nb_char, t_arg *arg)
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
	if (arg->precision > nb_char)
	{
		ft_putnchar('0', arg->precision - nb_char);
		g_bytes += arg->precision - nb_char;
	}
	if (!(nb == 0 && arg->precision == 0))
	{
		ft_put_ullong_base(nb, 10);
		g_bytes += nb_char;
	}
}
