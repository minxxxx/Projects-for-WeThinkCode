/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 15:54:28 by antoinebungert    #+#    #+#             */
/*   Updated: 2016/01/26 16:51:45 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_string(t_tag *tag, char *str)
{
	int		str_len;

	str_len = tag->has_precision ? ft_strnlen(str, tag->precision) :
										ft_strlen(str);
	if (tag->has_width && !tag->flag_minus)
		print_width_pad(str_len, tag->width, tag->flag_zero ?
			'0' : ' ');
	ft_putnstr(str, str_len);
	if (tag->has_width && tag->flag_minus)
		print_width_pad(str_len, tag->width, ' ');
	return (tag->has_width ? ft_max(tag->width, str_len) : str_len);
}

int		convert_string(t_tag *tag, va_list *args)
{
	char	*output_arg;

	if (tag->length == 3)
		return (convert_wstring(tag, args));
	output_arg = va_arg(*args, char *);
	if (output_arg != NULL)
		return (print_string(tag, output_arg));
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
