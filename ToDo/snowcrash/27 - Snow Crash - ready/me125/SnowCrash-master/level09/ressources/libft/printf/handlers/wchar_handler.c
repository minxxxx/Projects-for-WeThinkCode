/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:09:28 by dgalide           #+#    #+#             */
/*   Updated: 2016/03/03 16:09:29 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*wchar_handler_ext(wchar_t chr)
{
	char *str;

	str = ft_memset(ft_strnew(4), '\0', 4);
	if (chr <= 0x7F)
		str[0] = chr;
	else if (chr <= 0x7FF)
	{
		str[0] = ((chr >> 6) + 0xC0);
		str[1] = ((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0xFFFF)
	{
		str[0] = ((chr >> 12) + 0xE0);
		str[1] = (((chr >> 6) & 0x3F) + 0x80);
		str[2] = ((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0x10FFFF)
	{
		str[0] = ((chr >> 18) + 0xF0);
		str[1] = (((chr >> 12) & 0x3F) + 0x80);
		str[2] = (((chr >> 6) & 0x3F) + 0x80);
		str[3] = ((chr & 0x3F) + 0x80);
	}
	return (str);
}

void		wchar_handler_ext_2(t_data *data, int tmp, char *str)
{
	if (tmp == 1 && data->flag.minus)
	{
		write(1, "\0", 1);
		write(1, str, ft_strlen(str));
	}
	else if (!(data->flag.minus) && tmp == 1)
	{
		write(1, str, ft_strlen(str));
		write(1, "\0", 1);
	}
	else
		write(1, str, ft_strlen(str));
}

void		wchar_handler(t_data *data, va_list arg)
{
	char	*str;
	int		tmp;
	wchar_t	chr;

	chr = (wchar_t)va_arg(arg, void *);
	tmp = 0;
	if (chr == 0)
	{
		data->final_len += 1;
		data->minimal_range = (data->minimal_range > 0) ?
		data->minimal_range - 1 : data->minimal_range;
		tmp = 1;
	}
	str = wchar_handler_ext(chr);
	if (tmp == 1)
		ft_memdel((void **)&str);
	generic_range_handler(data, &str);
	data->final_len += ft_strlen(str);
	wchar_handler_ext_2(data, tmp, str);
	ft_memdel((void **)&str);
}
