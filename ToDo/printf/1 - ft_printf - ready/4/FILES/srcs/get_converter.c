/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 10:36:57 by abungert          #+#    #+#             */
/*   Updated: 2016/02/01 16:38:10 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_valid_specifier(char c)
{
	char	*authorized;

	authorized = "sSpdDioOuUxXcCb%";
	if (!ft_strchr(authorized, c))
		return (0);
	return (1);
}

void		adjust_format(t_tag *tag)
{
	if (tag->flag_minus || tag->has_precision == 1 || tag->specifier == 'p')
		tag->flag_zero = 0;
	if (tag->specifier != 'o' && tag->specifier != 'x' && tag->specifier != 'X'
			&& tag->specifier != 'O')
		tag->flag_sharp = 0;
	if ((tag->has_width && !tag->flag_zero) || tag->flag_plus
			|| tag->specifier == 'p'
			|| (tag->specifier != 'd' && tag->specifier != 'i'))
		tag->flag_space = 0;
	if (tag->specifier != 'd' && tag->specifier != 'i' && tag->specifier != 'D')
		tag->flag_plus = 0;
	if (tag->has_precision == 2 && tag->specifier == 's')
		tag->precision = 0;
}

t_converter	return_converter(char c)
{
	if (c == 'd' || c == 'i')
		return (&convert_int);
	else if (c == 'u')
		return (&convert_unsigned_int);
	else if (c == 'o')
		return (&convert_octal);
	else if (c == 'D' || c == 'U' || c == 'O')
		return (&convert_long);
	else if (c == 'x' || c == 'X')
		return (&convert_hexa);
	else if (c == 'c')
		return (&convert_char);
	else if (c == 's')
		return (&convert_string);
	else if (c == 'p')
		return (&convert_address);
	else if (c == '%')
		return (&convert_escape);
	else if (c == 'C')
		return (&convert_wchar);
	else if (c == 'S')
		return (&convert_wstring);
	else if (c == 'b')
		return (&convert_binary);
	return (NULL);
}
