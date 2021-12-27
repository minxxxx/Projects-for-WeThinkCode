/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 19:01:58 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/27 19:20:15 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			print_char_and_padding(t_conversion *conversion
											, char argument, char *string
											, t_format *format)
{
	if (argument)
		ft_putstr(string);
	else
	{
		if (conversion->flags.left_justify)
			ft_putchar('\0');
		ft_putstr(string);
		if (!conversion->flags.left_justify)
			ft_putchar('\0');
		format->written++;
	}
	format->written += ft_strlen(string);
}

void				print_char(t_conversion *conversion, char argument
								, t_format *format)
{
	char			*string;

	string = ft_strnew(1);
	string[0] = argument;
	if (!argument && conversion->width)
		conversion->width--;
	add_final_padding(conversion, &string);
	print_char_and_padding(conversion, argument, string, format);
}
