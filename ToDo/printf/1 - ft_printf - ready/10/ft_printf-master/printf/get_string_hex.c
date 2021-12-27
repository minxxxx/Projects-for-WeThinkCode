/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 20:12:16 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 15:26:13 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*get_string_hex(t_conversion *conversion
										, va_list arguments)
{
	char			*string;
	char			*final;
	uintmax_t		value;
	t_bool			is_zero_value;

	value = get_unsigned_number_argument(conversion->length, arguments);
	if (!value && conversion->precision_set)
		string = ft_strdup("");
	else
		string = ft_basetoa(value, 16);
	if (conversion->specifier == HEX_LOWER)
		ft_strtolower(string);
	is_zero_value = string[0] == '0' || string[0] == '\0';
	add_precision_padding(conversion, &string);
	if ((conversion->flags.hashtag && !is_zero_value)
		&& !(conversion->precision_set && conversion->precision == 0))
	{
		final = ft_strjoin(conversion->specifier == HEX_LOWER ? "0x" : "0X"
							, string);
		free(string);
	}
	else
		final = string;
	return (final);
}
