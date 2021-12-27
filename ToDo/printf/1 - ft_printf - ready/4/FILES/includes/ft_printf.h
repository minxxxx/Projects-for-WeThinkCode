/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 16:07:46 by dtedgui           #+#    #+#             */
/*   Updated: 2016/02/01 11:52:29 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

# include "tag_struct.h"

int				ft_printf(const char *format, ...);

typedef int		(*t_converter)(t_tag *, va_list *);
t_converter		return_converter(char c);

void			get_flags(char **format, t_tag *tag);
void			get_width(char **format, t_tag *tag);
void			get_precision(char **format, t_tag *tag);
void			get_length(char **format, t_tag *tag);
void			get_specifier(char **format, t_tag *tag);
int				is_valid_specifier(char c);
void			adjust_format(t_tag *tag);
int				print_forceprefix(t_tag *tag, uintmax_t nbr,
	char *prefix, char *base);
int				print_forceprefix_max(t_tag *tag, intmax_t nbr,
	char *prefix, char *base);
unsigned int	nbr_length(uintmax_t nbr, char *base);
unsigned int	nbr_strlength(t_tag *tag, uintmax_t nbr, char *base);
int				nbr_length_max(intmax_t nbr, char *base);
int				nbr_strlength_max(t_tag *tag, intmax_t nbr, char *base);
void			print_width_pad(int nbr_len, int width, char pad);
int				convert_int(t_tag *tag, va_list *args);
int				convert_unsigned_int(t_tag *tag, va_list *args);
int				convert_octal(t_tag *tag, va_list *args);
int				convert_hexa(t_tag *tag, va_list *args);
int				convert_char(t_tag *tag, va_list *args);
int				convert_string(t_tag *tag, va_list *args);
int				convert_address(t_tag *tag, va_list *args);
int				convert_escape(t_tag *tag, va_list *args);
int				convert_long(t_tag *tag, va_list *args);
int				convert_wchar(t_tag *tag, va_list *args);
int				convert_wstring(t_tag *tag, va_list *args);
int				convert_binary(t_tag *tag, va_list *args);
uintmax_t		get_unsigned_length(uintmax_t nbr, t_tag *tag);
intmax_t		get_signed_length(intmax_t nbr, t_tag *tag);
int				add_color(char **format);
void			print_char(t_tag *tag, char c);
int				print_int(t_tag *tag, intmax_t nbr);
int				print_string(t_tag *tag, char *str);
int				print_uint(t_tag *tag, uintmax_t nbr, char *base, char *prefix);
void			print_wchar(t_tag *tag, wchar_t c);
int				print_wstring(t_tag *tag, wchar_t *str);

#endif
