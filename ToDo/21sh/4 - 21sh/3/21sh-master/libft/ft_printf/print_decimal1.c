/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 12:40:46 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/12 17:49:59 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero_space_decimal(long long nb, int nb_char, t_arg *arg)
{
	if (arg->width > arg->precision && arg->precision > -1)
		zero_space_decimal1(nb, nb_char, arg);
	else
	{
		nb < 0 ? ft_putchar('-') : ft_putchar(' ');
		nb_char = nb < 0 ? nb_char - 1 : nb_char;
		nb = nb < 0 ? -nb : nb;
		arg->width--;
		if (arg->width > nb_char && arg->precision == -1)
		{
			ft_putnchar('0', arg->width - nb_char);
			g_bytes += arg->width - nb_char;
		}
		else if (arg->precision > nb_char)
		{
			ft_putnchar('0', arg->precision - nb_char);
			g_bytes += arg->precision - nb_char;
		}
		ft_put_llong_base(nb, 10);
		g_bytes += nb_char + 1;
	}
}

void	zero_space_decimal1(long long nb, int nb_char, t_arg *arg)
{
	int	n;

	if (arg->precision > nb_char && nb < 0)
		arg->width--;
	n = arg->precision > nb_char ? arg->width - arg->precision :
		arg->width - nb_char;
	ft_putnchar(' ', n);
	g_bytes += n;
	if (nb < 0 && --nb_char && ++g_bytes)
		ft_putchar('-');
	nb = nb < 0 ? -nb : nb;
	if (arg->precision > nb_char)
	{
		ft_putnchar('0', arg->precision - nb_char);
		g_bytes += arg->precision - nb_char;
	}
	if (nb == 0 && arg->precision == 0 && ++g_bytes)
		ft_putchar(' ');
	else
	{
		ft_put_llong_base(nb, 10);
		g_bytes += nb_char;
	}
}

void	plus_decimal(long long nb, int nb_char, t_arg *arg)
{
	if (arg->width && arg->width > arg->precision)
		plus_decimal1(nb, nb_char, arg);
	else
	{
		nb < 0 ? ft_putchar('-') : ft_putchar('+');
		nb_char = nb < 0 ? nb_char - 1 : nb_char;
		nb = nb < 0 ? -nb : nb;
		arg->width--;
		if (arg->width > nb_char && arg->precision == -1)
		{
			ft_putnchar('0', arg->width - nb_char);
			g_bytes += arg->width - nb_char;
		}
		else if (arg->precision > nb_char)
		{
			ft_putnchar('0', arg->precision - nb_char);
			g_bytes += arg->precision - nb_char;
		}
		ft_put_llong_base(nb, 10);
		g_bytes += nb_char + 1;
	}
}

void	plus_decimal1(long long nb, int nb_char, t_arg *arg)
{
	int	n;

	if (arg->precision > nb_char)
		arg->width--;
	n = arg->precision > nb_char ? arg->width - arg->precision :
		arg->width - nb_char;
	ft_putnchar(' ', n);
	g_bytes += n + 1;
	nb < 0 ? ft_putchar('-') : ft_putchar('+');
	nb_char = nb < 0 ? nb_char - 1 : nb_char;
	nb = nb < 0 ? -nb : nb;
	if (arg->precision > nb_char)
	{
		ft_putnchar('0', arg->precision - nb_char);
		g_bytes += arg->precision - nb_char;
	}
	if (!(nb == 0 && arg->precision == 0))
	{
		ft_put_llong_base(nb, 10);
		g_bytes += nb_char;
	}
}
