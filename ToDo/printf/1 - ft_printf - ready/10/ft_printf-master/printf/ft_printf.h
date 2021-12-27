/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 16:36:32 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 15:01:15 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** looking for specifications? look no futher!
** http://pubs.opengroup.org/onlinepubs/9699919799/functions/printf.html
*/

/*
** stdarg: unknown number of arguments
** wchar: wide characters
** limits: upper and lower values of primitive types
*/

# include "libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>

# define PROGRAM_NAME					"ft_printf"
# define ERROR							1
# define OKAY							0
# define LARGEST_STAR_ARGUMENT			((unsigned int)INT_MAX)

typedef char			t_bool;

typedef struct			s_format
{
	const char	*string;
	size_t		location;
	size_t		written;
}						t_format;

typedef struct			s_flags
{
	t_bool		left_justify;
	t_bool		pad_with_zeros;
	t_bool		show_sign;
	t_bool		positive_values_begin_blank;
	t_bool		hashtag;
}						t_flags;

/*
** sorted by size (generally speaking)
** DEFAULT_LENGTH because bzero at beginning has to make new conversion
*/

typedef enum			e_length
{
	DEFAULT_LENGTH, HH, H, L, LL, J, Z
}						t_length;

/*
** see parse_specifier for more specifier table
*/

typedef enum			e_specifier
{
	S_DECIMAL, U_DECIMAL, OCTAL, HEX_LOWER, HEX_UPPER, CHAR, STRING, POINTER
	, INVALID_SPECIFIER
}						t_specifier;

typedef struct			s_conversion
{
	t_flags				flags;
	unsigned int		width;
	unsigned int		precision;
	t_bool				precision_set;
	t_length			length;
	t_specifier			specifier;
}						t_conversion;

/*
** used to get the strings
*/

int						ft_printf(const char *format_string, ...);
void					handle_format(t_format *format, va_list arguments);
int						parse_conversion(t_conversion *conversion
											, va_list arguments
											, t_format *format);
int						parse_flags(t_conversion *conversion, t_format *format);
int						parse_width(t_conversion *conversion
									, va_list arguments
									, t_format *format);
int						parse_precision(t_conversion *conversion
										, va_list arguments
										, t_format *format);
int						parse_length(t_conversion *conversion
											, t_format *format);
int						parse_specifier(t_conversion *conversion
											, t_format *format);
int						validate_conversion(t_conversion *conversion
											, t_format *format);
int						validate_flags(t_conversion *conversion
											, t_format *format);
void					validate_flags_ignored(t_conversion *conversion
											, t_format *format);
void					print_conversion(t_conversion *conversion
											, va_list arguments
											, t_format *format);
void					print_normal(t_conversion *conversion
											, va_list arguments
											, t_format *format);
void					print_char(t_conversion *conversion, char argument
											, t_format *format);
void					print_wide_chars(t_conversion *conversion
											, wchar_t *string, size_t length
											, size_t *written);
void					print_format_error(t_format *format);
const char				*get_current(t_format *format);
intmax_t				get_number_argument(t_length length, va_list arguments);
uintmax_t				get_unsigned_number_argument(t_length length
														, va_list arguments);
char					*get_string_decimal(t_conversion *conversion
											, va_list arguments);
char					*get_string_string(t_conversion *conversion
											, va_list arguments);
char					*get_string_pointer(t_conversion *conversion
											, va_list arguments);
char					*get_string_hex(t_conversion *conversion
											, va_list arguments);
char					*get_string_octal(t_conversion *conversion
											, va_list arguments);
void					add_final_padding(t_conversion *conversion
											, char **string);
void					add_precision_padding(t_conversion *conversion
											, char **string);

#endif
