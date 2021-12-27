/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 19:10:53 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/27 19:11:06 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*(*get_string_getter(t_specifier specifier))()
{
	if (specifier == STRING)
		return (get_string_string);
	else if (specifier == POINTER)
		return (get_string_pointer);
	else if (specifier == OCTAL)
		return (get_string_octal);
	else if (specifier == HEX_UPPER || specifier == HEX_LOWER)
		return (get_string_hex);
	return (get_string_decimal);
}

void				print_normal(t_conversion *conversion
									, va_list arguments
									, t_format *format)
{
	char			*string;
	char			*(*getter)();

	getter = get_string_getter(conversion->specifier);
	string = getter(conversion, arguments, format);
	add_final_padding(conversion, &string);
	ft_putstr(string);
	format->written += ft_strlen(string);
	free(string);
}
