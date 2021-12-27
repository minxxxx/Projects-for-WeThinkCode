/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 17:21:41 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/31 15:55:18 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define BLACK	"\033[0;30m"
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[0;34m"
# define PURPLE	"\033[0;35m"
# define CYAN	"\033[1;36m"
# define WHITE	"\033[1;m"
# define OFF	"\033[0;m"

typedef struct		s_arg
{
	char			letter;
	int				l;
	int				ll;
	int				h;
	int				hh;
	int				j;
	int				z;
	int				sharp;
	int				zero;
	int				minus;
	int				plus;
	int				space;
	int				width;
	int				precision;
}					t_arg;

int					g_bytes;

int					ft_printf(const char *format, ...);
void				ft_put_ulong_base(unsigned long n, unsigned int base);
void				ft_put_llong_base(long long n, unsigned int base);
void				ft_put_ullong_base(unsigned long long n, unsigned int base);
void				ft_put_ullong_base_upper(unsigned long long n,
					unsigned int base);

int					print_format(va_list ap, const char *format);
int					set_arg(va_list ap, const char *format, int start);
void				init_struct(t_arg *arg);
int					store_arg(va_list ap, char *argument, t_arg *arg);
int					check_flags(char *argument, t_arg *arg);
int					check_width(va_list ap, char *argument, t_arg *arg, int i);
int					check_precision(va_list ap, char *argument,
					t_arg *arg, int i);
int					check_l_modifier(char *argument, t_arg *arg, int i);
int					check_h_modifier(char *argument, t_arg *arg, int i);
int					check_j_modifier(char *argument, t_arg *arg, int i);
int					check_z_modifier(char *argument, t_arg *arg, int i);
int					check_struct(t_arg *arg);

char				*uint_to_binary(unsigned int n);
int					binary_to_int(char *bits, int i);
char				*set_unicode_binary(char *bits, int i);
void				display_wchar(wchar_t c);
void				display_wchar1(char *bits, int i);
void				display_wchar_string(wchar_t *s);

int					count_wchar_bytes(wchar_t c);
int					count_wchar_string_bytes(wchar_t *s);
int					count_char_signed_decimal_base(long long nb,
					unsigned int base);
int					count_char_usigned_decimal_base(unsigned long long nb,
					unsigned int base);

void				print_arg(va_list ap, t_arg *arg);
void				print_string(va_list ap, t_arg *arg);
void				print_address(va_list ap, t_arg *arg);
void				print_char(va_list ap, t_arg *arg);
void				print_wchar_t(va_list ap, t_arg *arg);
void				print_string(va_list ap, t_arg *arg);
void				print_wchar_string(va_list ap, t_arg *arg);
void				print_percent(t_arg *arg);
void				print_signed_decimal(long long nb, t_arg *arg);
void				print_usigned_decimal(unsigned long long nb, t_arg *arg);
void				print_octal(unsigned long long nb, t_arg *arg);
void				print_hexa(unsigned long long nb, t_arg *arg);
void				print_hexa_upper(unsigned long long nb, int nb_char,
					t_arg *arg);

void				flags_on_char(int c, t_arg *arg);
void				flags_on_wchar(wchar_t c, int nb_bytes, t_arg *arg);
void				flags_on_string(char *s, t_arg *arg);
void				flags_on_wchar_string1(wchar_t *s, int nb_bytes,
					t_arg *arg);
void				flags_on_wchar_string2(wchar_t *s, int nb_bytes,
					t_arg *arg);
void				flags_on_wchar_string3(wchar_t *s, int nb_bytes,
					t_arg *arg);
void				minus_address(unsigned long addr, int nb_char, t_arg *arg);
void				no_minus_address(unsigned long addr, int nb_char,
					t_arg *arg);
void				zero_address(unsigned long addr, int nb_char, t_arg *arg);
void				minus_plus_decimal(long long nb, int nb_char, t_arg *arg);
void				minus_space_decimal(long long nb, int nb_char, t_arg *arg);
void				minus_decimal(long long nb, int nb_char, t_arg *arg);
void				zero_plus_decimal(long long nb, int nb_char, t_arg *arg);
void				zero_space_decimal(long long nb, int nb_char, t_arg *arg);
void				zero_space_decimal1(long long nb, int nb_char, t_arg *arg);
void				zero_space_decimal2(long long nb, int nb_char, t_arg *arg);
void				zero_decimal(long long nb, int nb_char, t_arg *arg);
void				zero_decimal1(long long nb, int nb_char, t_arg *arg);
void				plus_decimal(long long nb, int nb_char, t_arg *arg);
void				plus_decimal1(long long nb, int nb_char, t_arg *arg);
void				space_decimal(long long nb, int nb_char, t_arg *arg);
void				space_decimal1(long long nb, int nb_char, t_arg *arg);
void				no_flag_decimal(long long nb, int nb_char, t_arg *arg);
void				no_flag_decimal1(long long nb, int nb_char, t_arg *arg);
void				minus_udecimal(unsigned long long nb, int nb_char,
					t_arg *arg);
void				zero_udecimal(unsigned long long nb, int nb_char,
					t_arg *arg);
void				no_flag_udecimal(unsigned long long nb, int nb_char,
					t_arg *arg);
void				minus_octal(unsigned long long nb, int nb_char, t_arg *arg);
void				zero_octal(unsigned long long nb, int nb_char, t_arg *arg);
void				no_flag_octal(unsigned long long nb, int nb_char,
					t_arg *arg);
void				minus_hexa(unsigned long long nb, int nb_char, t_arg *arg);
void				zero_hexa(unsigned long long nb, int nb_char, t_arg *arg);
void				no_flag_hexa(unsigned long long nb, int nb_char,
					t_arg *arg);
void				minus_hexa_upper(unsigned long long nb, int nb_char,
					t_arg *arg);
void				zero_hexa_upper(unsigned long long nb, int nb_char,
					t_arg *arg);
void				no_flag_hexa_upper(unsigned long long nb, int nb_char,
					t_arg *arg);

#endif
