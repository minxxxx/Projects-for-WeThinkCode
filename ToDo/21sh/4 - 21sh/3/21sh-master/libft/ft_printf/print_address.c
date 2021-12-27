/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 22:34:58 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/12 17:46:25 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_address(va_list ap, t_arg *arg)
{
	unsigned long	addr;
	unsigned long	save;
	int				nb_char;

	nb_char = 0;
	addr = (unsigned long)va_arg(ap, void *);
	save = addr;
	while (save > 0 && ++nb_char)
		save = save / 16;
	if (addr == 0 && arg->precision != 0)
		nb_char = 1;
	if (arg->minus)
		minus_address(addr, nb_char, arg);
	else if (arg->zero)
		zero_address(addr, nb_char, arg);
	else
		no_minus_address(addr, nb_char, arg);
}

void	minus_address(unsigned long addr, int nb_char, t_arg *arg)
{
	ft_putstr("0x");
	if (arg->precision > nb_char)
	{
		ft_putnchar('0', arg->precision - nb_char);
		g_bytes += arg->precision - nb_char;
	}
	if (!(addr == 0 && arg->precision == 0))
		ft_put_ulong_base(addr, 16);
	g_bytes += nb_char + 2;
	if (arg->width > (nb_char + 2) && arg->width > (arg->precision + 2))
	{
		if (arg->precision > nb_char)
		{
			ft_putnchar(' ', arg->width - arg->precision - 2);
			g_bytes += arg->width - arg->precision - 2;
		}
		else if (nb_char >= arg->precision)
		{
			ft_putnchar(' ', arg->width - nb_char - 2);
			g_bytes += arg->width - nb_char - 2;
		}
	}
}

void	zero_address(unsigned long addr, int nb_char, t_arg *arg)
{
	int	n;

	n = arg->precision > nb_char ? arg->width - arg->precision :
		arg->width - nb_char;
	if (arg->width > (arg->precision + 2) && arg->width > (nb_char + 2)
		&& arg->precision > -1)
	{
		ft_putnchar(' ', n - 2);
		g_bytes += n - 2;
	}
	ft_putstr("0x");
	if (arg->width > (arg->precision + 2) && arg->width > (nb_char + 2)
	&& arg->precision == -1)
	{
		ft_putnchar('0', arg->width - nb_char - 2);
		g_bytes += arg->width - nb_char - 2;
	}
	if (arg->precision > nb_char)
	{
		ft_putnchar('0', arg->precision - nb_char);
		g_bytes += arg->precision - nb_char;
	}
	if (!(addr == 0 && arg->precision == 0))
		ft_put_ulong_base(addr, 16);
	g_bytes += nb_char + 2;
}

void	no_minus_address(unsigned long addr, int nb_char, t_arg *arg)
{
	if (arg->width > (arg->precision + 2) && arg->precision > nb_char)
	{
		ft_putnchar(' ', arg->width - arg->precision - 2);
		g_bytes += arg->width - arg->precision - 2;
	}
	else if (arg->width > (nb_char + 2) && nb_char >= arg->precision)
	{
		ft_putnchar(' ', arg->width - nb_char - 2);
		g_bytes += arg->width - nb_char - 2;
	}
	ft_putstr("0x");
	if (arg->precision > nb_char)
	{
		ft_putnchar('0', arg->precision - nb_char);
		g_bytes += arg->precision - nb_char;
	}
	if (!(addr == 0 && arg->precision == 0))
		ft_put_ulong_base(addr, 16);
	g_bytes += nb_char + 2;
}
