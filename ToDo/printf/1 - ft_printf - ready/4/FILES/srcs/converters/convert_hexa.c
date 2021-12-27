/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 10:36:57 by abungert          #+#    #+#             */
/*   Updated: 2016/02/01 13:06:57 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_hexa(t_tag *tag, va_list *args)
{
	uintmax_t		output_arg;

	output_arg = va_arg(*args, uintmax_t);
	output_arg = get_unsigned_length(output_arg, tag);
	if (output_arg == 0 && tag->has_precision &&
		(tag->precision == 1 || tag->precision == 0))
	{
		if (!tag->has_width)
			return (tag->precision = 0);
		else
		{
			print_width_pad(0, tag->width, ' ');
			return (tag->width);
		}
	}
	if (tag->specifier == 'x')
		return (print_uint(tag, output_arg, "0123456789abcdef", "0x"));
	else
		return (print_uint(tag, output_arg, "0123456789ABCDEF", "0X"));
}
