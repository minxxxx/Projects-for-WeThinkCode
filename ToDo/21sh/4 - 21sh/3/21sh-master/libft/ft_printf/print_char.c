/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 10:28:40 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/12 17:49:20 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(va_list ap, t_arg *arg)
{
	int	nb;

	nb = va_arg(ap, int);
	if (arg->width > 1)
		flags_on_char(nb, arg);
	else
	{
		ft_putchar(nb);
		g_bytes++;
	}
}

void	print_wchar_t(va_list ap, t_arg *arg)
{
	wchar_t	c;
	int		nb_bytes;

	c = va_arg(ap, wchar_t);
	nb_bytes = count_wchar_bytes(c);
	if (arg->width > nb_bytes)
		flags_on_wchar(c, nb_bytes, arg);
	else
	{
		if (c != 0)
			display_wchar(c);
		g_bytes += nb_bytes;
	}
}

void	flags_on_char(int c, t_arg *arg)
{
	if (arg->minus)
	{
		ft_putchar(c);
		ft_putnchar(' ', arg->width - 1);
	}
	else
	{
		arg->zero ? ft_putnchar('0', arg->width - 1) :
		ft_putnchar(' ', arg->width - 1);
		ft_putchar(c);
	}
	g_bytes += arg->width;
}

void	flags_on_wchar(wchar_t c, int nb_bytes, t_arg *arg)
{
	int	n;

	n = arg->width - nb_bytes;
	if (arg->minus)
	{
		if (c != 0)
			display_wchar(c);
		ft_putnchar(' ', n);
	}
	else
	{
		ft_putnchar(' ', n);
		if (c != 0)
			display_wchar(c);
	}
	g_bytes += arg->width;
}
