/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 19:48:22 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 16:23:11 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** di		signed		decimal
** D		signed		decimal			l
** u		unsigned	decimal
** U		unsigned	decimal			l
** o		unsigned	octal
** O		unsigned	octal			l
** x		unsigned	hex (lowercase)
** X		unsigned	hex (uppercase)
** c		int
** C		wint_t						l
** s		char
** S		char*						l
** p		pointer
*/

static int			reached_end_while_parsing(t_format *format)
{
	if (*(format->string - 1) == '%')
		ft_putstr_fd("ft_printf: spurious trailing '%' in format\n", 2);
	else
		ft_putstr_fd("ft_printf: conversion lacks type at end of format\n", 2);
	print_format_error(format);
	return (1);
}

static int			invalid_specifier(char c, t_format *format)
{
	ft_putstr_fd("ft_printf: unknown conversion type character '", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("' in format\n", 2);
	print_format_error(format);
	return (1);
}

static int			mixed_masquerading_and_length(t_length length, char c
													, t_format *format)
{
	ft_putstr_fd("ft_printf: use of '", 2);
	if (length == HH || length == LL)
		ft_putstrn_fd(get_current(format) - 2, 2, 2);
	else
		ft_putstrn_fd(get_current(format) - 1, 1, 2);
	ft_putstr_fd("' length modifier with '", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("' type character\n", 2);
	print_format_error(format);
	return (1);
}

static t_specifier	get_specifier(char c)
{
	if (c == 'd' || c == 'i' || c == 'D')
		return (S_DECIMAL);
	if (c == 'u' || c == 'U')
		return (U_DECIMAL);
	if (c == 'o' || c == 'O')
		return (OCTAL);
	if (c == 'x')
		return (HEX_LOWER);
	if (c == 'X')
		return (HEX_UPPER);
	if (c == 'c' || c == 'C')
		return (CHAR);
	if (c == 's' || c == 'S')
		return (STRING);
	if (c == 'p')
		return (POINTER);
	return (INVALID_SPECIFIER);
}

int					parse_specifier(t_conversion *conversion
									, t_format *format)
{
	char			current;

	if (!((current = *get_current(format))))
		return (reached_end_while_parsing(format));
	conversion->specifier = get_specifier(current);
	if (conversion->specifier == INVALID_SPECIFIER)
		return (invalid_specifier(current, format));
	if (current == 'D' || current == 'U' || current == 'O'
		|| current == 'C' || current == 'S')
	{
		if (conversion->length != DEFAULT_LENGTH)
			mixed_masquerading_and_length(conversion->length
											, current, format);
		conversion->length = L;
	}
	format->location++;
	return (0);
}
