/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 19:49:28 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 15:44:46 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			add_precision(t_conversion *conversion, char **string)
{
	char			*new;

	if (ft_strlen(*string) > conversion->precision && conversion->precision_set)
	{
		new = ft_strnew(conversion->precision);
		ft_strncpy(*string, new, conversion->precision);
		free(*string);
		*string = new;
	}
}

char				*get_string_string(t_conversion *conversion
										, va_list arguments)
{
	char			*string;

	if (!(string = va_arg(arguments, char*)))
		return (ft_strdup("(null)"));
	string = ft_strdup(string);
	add_precision(conversion, &string);
	return (string);
}
