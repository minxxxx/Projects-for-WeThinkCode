/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_wchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 14:21:08 by abungert          #+#    #+#             */
/*   Updated: 2016/01/26 16:54:28 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		charwlen(wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else
		return (4);
}

void			print_wchar(t_tag *tag, wchar_t c)
{
	if (tag->has_width && !tag->flag_minus && !tag->flag_zero)
		print_width_pad(1, tag->width, ' ');
	else if (tag->has_width && tag->flag_zero)
		print_width_pad(1, tag->width, '0');
	ft_putwchar(c);
	if (tag->has_width && tag->flag_minus)
		print_width_pad(1, tag->width, ' ');
}

int				convert_wchar(t_tag *tag, va_list *args)
{
	wchar_t		output_arg;

	output_arg = va_arg(*args, int);
	print_wchar(tag, output_arg);
	if (tag->width >= charwlen(output_arg))
		return (tag->width);
	else
		return (charwlen(output_arg));
}
