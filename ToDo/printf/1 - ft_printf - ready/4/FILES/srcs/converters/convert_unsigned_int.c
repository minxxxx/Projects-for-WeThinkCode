/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unsigned_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 10:36:57 by abungert          #+#    #+#             */
/*   Updated: 2016/01/28 12:08:00 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_unsigned_int(t_tag *tag, va_list *args)
{
	uintmax_t		output_arg;

	output_arg = va_arg(*args, uintmax_t);
	output_arg = get_unsigned_length(output_arg, tag);
	if (output_arg == 0 && tag->has_precision &&
		(tag->precision == 1 || tag->precision == 0))
		return (tag->precision = 0);
	return (print_uint(tag, output_arg, "0123456789", NULL));
}
