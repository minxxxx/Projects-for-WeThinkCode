/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 12:40:46 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/12 17:49:45 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_signed_decimal(long long nb, t_arg *arg)
{
	int	nb_char;

	nb_char = count_char_signed_decimal_base(nb, 10);
	if (arg->minus && arg->plus)
		minus_plus_decimal(nb, nb_char, arg);
	else if (arg->minus && arg->space)
		minus_space_decimal(nb, nb_char, arg);
	else if (arg->minus)
		minus_decimal(nb, nb_char, arg);
	else if (arg->zero && arg->plus && arg->precision == -1)
		zero_plus_decimal(nb, nb_char, arg);
	else if (arg->zero && arg->space)
		zero_space_decimal(nb, nb_char, arg);
	else if (arg->plus || (arg->plus && arg->zero))
		plus_decimal(nb, nb_char, arg);
	else if (arg->zero)
		zero_decimal(nb, nb_char, arg);
	else if (arg->space)
		space_decimal(nb, nb_char, arg);
	else
		no_flag_decimal(nb, nb_char, arg);
}

void	minus_plus_decimal(long long nb, int nb_char, t_arg *arg)
{
	nb < 0 ? ft_putchar('-') : ft_putchar('+');
	nb_char = nb < 0 ? nb_char - 1 : nb_char;
	nb = nb < 0 ? -nb : nb;
	arg->width--;
	if (arg->precision > nb_char)
	{
		ft_putnchar('0', arg->precision - nb_char);
		g_bytes += arg->precision - nb_char;
	}
	ft_put_llong_base(nb, 10);
	g_bytes += nb_char + 1;
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

void	minus_space_decimal(long long nb, int nb_char, t_arg *arg)
{
	nb < 0 ? ft_putchar('-') : ft_putchar(' ');
	nb_char = nb < 0 ? nb_char - 1 : nb_char;
	nb = nb < 0 ? -nb : nb;
	arg->width--;
	if (arg->precision > nb_char)
	{
		ft_putnchar('0', arg->precision - nb_char);
		g_bytes += arg->precision - nb_char;
	}
	ft_put_llong_base(nb, 10);
	g_bytes += nb_char + 1;
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

void	minus_decimal(long long nb, int nb_char, t_arg *arg)
{
	if (nb < 0 && ++g_bytes && --nb_char && --arg->width)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (arg->precision > nb_char)
	{
		ft_putnchar('0', arg->precision - nb_char);
		g_bytes += arg->precision - nb_char;
	}
	ft_put_llong_base(nb, 10);
	g_bytes += nb_char;
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

void	zero_plus_decimal(long long nb, int nb_char, t_arg *arg)
{
	nb < 0 ? ft_putchar('-') : ft_putchar('+');
	nb_char = nb < 0 ? nb_char - 1 : nb_char;
	nb = nb < 0 ? -nb : nb;
	arg->width--;
	if (arg->width > nb_char)
	{
		ft_putnchar('0', arg->width - nb_char);
		g_bytes += arg->width - nb_char;
	}
	ft_put_llong_base(nb, 10);
	g_bytes += nb_char + 1;
}
