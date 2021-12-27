/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_octal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 20:05:01 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 15:44:36 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*get_string_octal(t_conversion *conversion
										, va_list arguments)
{
	char			*string;
	char			*final;
	uintmax_t		value;

	value = get_unsigned_number_argument(conversion->length, arguments);
	if (!value && conversion->precision_set)
		string = ft_strdup("");
	else
		string = ft_basetoa(value, 8);
	add_precision_padding(conversion, &string);
	if (conversion->flags.hashtag && string[0] != '0')
	{
		final = ft_strjoin("0", string);
		free(string);
	}
	else
		final = string;
	return (final);
}
