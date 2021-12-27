/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 04:09:42 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/03 04:20:41 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct	s_flag
{
	int			diez;
	int			zero;
	int			plus;
	int			minus;
	int			space;
}				t_flag;

typedef	struct	s_spec
{
	int			ll;
	int			l;
	int			h;
	int			hh;
	int			j;
	int			z;
}				t_spec;

typedef	struct	s_data
{
	t_flag		flag;
	t_spec		specifier;
	char		modifier;
	int			precision;
	int			precision_null;
	char		*setting;
	int			len_setting;
	int			minimal_range;
	char		*final_string;
	int			final_len;
	int			nb_arg;
}				t_data;

void			pointer_handler(t_data *data, va_list arg);
void			percent_handler(t_data *data);
void			decimal_handler(t_data *data, va_list arg);
void			char_handler(t_data *data, va_list arg);
void			generic_range_handler(t_data *data, char **s1);
void			string_handler(t_data *data, va_list arg);
void			wchar_handler(t_data *data, va_list arg);
void			wstring_handler(t_data *data, va_list arg);
void			unsigned_decimal_handler(t_data *data, va_list arg);
void			octal_handler(t_data *data, va_list arg);
void			hexadecimal_handler(t_data *data, va_list arg);

int				check_setting(char *format, int i);
int				search(t_data *data, int i, const char *format);
int				get_precision_len(t_data *data);
int				ft_is_flag(char c);

void			load_struct(t_data *data);
void			set_zero_data(t_data *data);
void			add_plus(char **str, t_data *data);
void			sign_replace(char **s1, char **s2);
void			add_diez(char **arg, int zero_bool);
void			replace_diez(char **arg);
void			struct_del(t_data *data);

int				ft_printf(const char *format, ...);
void			process(t_data *data, va_list arg);

#endif
