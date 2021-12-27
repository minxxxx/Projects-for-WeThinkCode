/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 23:03:06 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 15:34:11 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			print_wide_string(t_conversion *conversion
										, wchar_t *string
										, size_t *written)
{
	if (string)
		print_wide_chars(conversion, string, ft_strlen_wide(string), written);
	else
	{
		ft_putstr("(null)");
		*written += 6;
	}
}

static void			print_wide_char(t_conversion *conversion, wint_t wint
									, t_format *format)
{
	wchar_t	wchar;

	if (wint > 0x10FFFF)
	{
		ft_putstr_fd("ft_printf: invalid wide character encountered", 2);
		print_format_error(format);
	}
	else
	{
		wchar = (wchar_t)wint;
		print_wide_chars(conversion, &wchar, 1, &format->written);
	}
}

void				print_conversion(t_conversion *conversion, va_list arguments
										, t_format *format)
{
	if (conversion->length >= L && conversion->specifier == STRING)
		print_wide_string(conversion, va_arg(arguments, wchar_t*)
							, &format->written);
	else if (conversion->specifier == CHAR)
	{
		if (conversion->length >= L)
			print_wide_char(conversion, va_arg(arguments, wchar_t), format);
		else
			print_char(conversion, (char)va_arg(arguments, int), format);
	}
	else
		print_normal(conversion, arguments, format);
}
