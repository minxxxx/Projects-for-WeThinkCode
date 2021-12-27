/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 14:04:13 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/12 17:53:02 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display_wchar_string(wchar_t *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		display_wchar(s[i]);
		i++;
	}
}

void	print_wchar_string(va_list ap, t_arg *arg)
{
	int		nb_bytes;
	wchar_t	*s;

	if (!(s = va_arg(ap, wchar_t *)))
		s = L"(null)";
	nb_bytes = count_wchar_string_bytes(s);
	if (arg->minus && (arg->width > nb_bytes ||
				(arg->precision != -1 && arg->precision < nb_bytes)))
		flags_on_wchar_string1(s, nb_bytes, arg);
	else if (arg->width > nb_bytes ||
			(arg->precision != -1 && arg->precision < nb_bytes))
		flags_on_wchar_string2(s, nb_bytes, arg);
	else
	{
		display_wchar_string(s);
		g_bytes += nb_bytes;
	}
}

void	flags_on_wchar_string1(wchar_t *s, int nb_bytes, t_arg *arg)
{
	int	i;
	int	bytes;

	i = 0;
	bytes = 0;
	if (arg->precision < nb_bytes && arg->precision != -1)
	{
		while ((bytes += count_wchar_bytes(s[i])) <= arg->precision && i++)
			display_wchar(s[i]);
		bytes -= count_wchar_bytes(s[i]);
		g_bytes += bytes;
		if ((arg->width - bytes) > 0)
		{
			ft_putnchar(' ', (arg->width - bytes));
			g_bytes += (arg->width - bytes);
		}
	}
	else if (arg->width > nb_bytes)
	{
		display_wchar_string(s);
		ft_putnchar(' ', arg->width - nb_bytes);
		g_bytes += arg->width;
	}
}

void	flags_on_wchar_string2(wchar_t *s, int nb_bytes, t_arg *arg)
{
	int	i;
	int	j;
	int	bytes;

	i = 0;
	j = 0;
	bytes = 0;
	if (arg->precision < nb_bytes && arg->precision != -1)
	{
		while ((bytes += count_wchar_bytes(s[i])) <= arg->precision)
			i++;
		bytes -= count_wchar_bytes(s[i]);
		if ((arg->width - bytes) > 0)
		{
			arg->zero ? ft_putnchar('0', (arg->width - bytes)) :
				ft_putnchar(' ', (arg->width - bytes));
			g_bytes += (arg->width - bytes);
		}
		while (j < i && j++)
			display_wchar(s[j]);
		g_bytes += bytes;
	}
	else if (arg->width > nb_bytes)
		flags_on_wchar_string3(s, nb_bytes, arg);
}

void	flags_on_wchar_string3(wchar_t *s, int nb_bytes, t_arg *arg)
{
	arg->zero ? ft_putnchar('0', arg->width - nb_bytes) :
	ft_putnchar(' ', arg->width - nb_bytes);
	display_wchar_string(s);
	g_bytes += arg->width;
}
