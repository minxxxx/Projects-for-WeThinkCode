/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:30:41 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/26 11:55:25 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flags(char **format, t_tag *tag)
{
	while (**format && (**format == ' ' || **format == '-' || **format == '+'
			|| **format == '#' || **format == '0'))
	{
		if (**format == ' ')
			tag->flag_space = 1;
		else if (**format == '-')
			tag->flag_minus = 1;
		else if (**format == '+')
			tag->flag_plus = 1;
		else if (**format == '#')
			tag->flag_sharp = 1;
		else if (**format == '0')
			tag->flag_zero = 1;
		(*format)++;
	}
}

void	get_width(char **format, t_tag *tag)
{
	while (**format && ft_isdigit(**format))
	{
		tag->has_width = 1;
		tag->width = tag->width * 10 + (**format - 48);
		(*format)++;
	}
}

void	get_precision(char **format, t_tag *tag)
{
	if (**format == '.')
	{
		tag->has_precision = 1;
		(*format)++;
		if (!(ft_isdigit(**format)))
		{
			tag->has_precision = 2;
			tag->precision = 1;
		}
		while (**format && ft_isdigit(**format))
		{
			tag->precision = tag->precision * 10 + (**format - 48);
			(*format)++;
		}
	}
}

void	get_length(char **format, t_tag *tag)
{
	if (**format == 'h' || **format == 'l'
		|| **format == 'j' || **format == 'z')
	{
		if (**format == 'h')
		{
			tag->length = *(*format + 1) == 'h' ? 2 : 1;
			if (tag->length == 2)
				(*format)++;
		}
		else if (**format == 'l')
		{
			tag->length = *(*format + 1) == 'l' ? 4 : 3;
			if (tag->length == 4)
				(*format)++;
		}
		else if (**format == 'j')
			tag->length = 5;
		else if (**format == 'z')
			tag->length = 6;
		(*format)++;
	}
}

void	get_specifier(char **format, t_tag *tag)
{
	if (**format && is_valid_specifier(**format))
	{
		tag->specifier = **format;
		(*format)++;
	}
}
