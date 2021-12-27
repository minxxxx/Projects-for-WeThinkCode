/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_wstring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 14:23:47 by abungert          #+#    #+#             */
/*   Updated: 2016/01/26 16:55:05 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_wstring(t_tag *tag, wchar_t *str)
{
	int			str_len;

	str_len = tag->has_precision ? ft_strnwlen(str, tag->precision) :
										ft_strwlen(str);
	if (tag->has_width && !tag->flag_minus)
		print_width_pad(str_len, tag->width, tag->flag_zero ?
			'0' : ' ');
	ft_putnwstr(str, str_len);
	if (tag->has_width && tag->flag_minus)
		print_width_pad(str_len, tag->width, ' ');
	return (tag->has_width ? ft_max(tag->width, str_len) : str_len);
}

int				convert_wstring(t_tag *tag, va_list *args)
{
	wchar_t		*output_arg;

	output_arg = va_arg(*args, wchar_t *);
	if (output_arg != NULL)
		return (print_wstring(tag, output_arg));
	else if (tag->has_precision == 2)
	{
		print_width_pad(0, tag->width, '0');
		return (tag->width);
	}
	else
	{
		ft_putstr(NULL);
		return (6);
	}
}
