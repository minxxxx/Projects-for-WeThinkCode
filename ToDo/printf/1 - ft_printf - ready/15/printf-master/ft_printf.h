/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:45:42 by artemiy           #+#    #+#             */
/*   Updated: 2019/01/08 17:34:45 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

typedef struct  s_color
{
	char        *color;
	char        *replace;
}                t_color;

typedef struct s_flags
{
	int plus:2;
	int minus:2;
	int zero:2;
	int space:2;
	int cage:2;
}               t_flags;

typedef struct	s_specifier
{
	t_flags		*flags;
	int			width;
	int			precition;
	char		*length;
	char		specifier;
}				t_specifier;

typedef char *(*t_fn)(t_specifier *spec, va_list *ap);

/* t_specifier */
int				is_flag(char ch);
int				get_length_len(char *fmt);
int				get_width(char **fmt);
int				get_precition(char **fmt);
char			*get_length(char **fmt);
t_flags     	*get_flags(char **spec);
t_flags			*init_flags(void);
t_specifier		*create_specifier(char **fmt);
void			normalize_spec(t_specifier **spec);
void			spec_del(t_specifier **sp);
void			print_specifier(t_specifier *sp, int *counter);
void			handle_error(int code, t_specifier **sp);
int				is_valid_spec(t_specifier **sp, int *done);
/* converting int and float to str */
char			*ft_ullitoa(unsigned long long n);
char			*ft_llitoa(long long int n);
char			*ft_ftoa(long double num, int precition);
char 			*ft_ullitoa_base(unsigned long long num, const char *sym, int base);
char			*ft_uint_to_str(unsigned long long i, t_specifier *spec);
char			*ft_int_to_str(long long i, int precition);
char			*ft_fillstr(int len, char ch);
char			*ft_dispatch_uint(t_specifier *spec, va_list *ap);
char			*ft_upper_dispatch_uint(t_specifier *spec, va_list *ap);
char			*ft_dispatch_int(t_specifier *spec, va_list *ap);
char			*ft_upper_dispatch_int(t_specifier *spec, va_list *ap);
char			*ft_dispatch_float(t_specifier *spec, va_list *ap);
char			*ft_dispatch_e(t_specifier *spec, va_list *ap);
char			*ft_dispatch_g(t_specifier *spec, va_list *ap);
char			*ft_add_fract(char *int_str, long long fract, int precition);
long long		ft_pow(long long base, long long power);
char			*ft_double_to_exp(long double num, int precition, char specifier);
int				ft_get_exponent(char *str);

/* char and str */
char    		*ft_get_char(t_specifier *spec, va_list *ap);
char    		*ft_get_str(t_specifier *spec, va_list *ap);
char            *ft_strreplace(char *source, char *replace, char *str);
char            *ft_get_nstr(t_specifier *spec, va_list *ap);
char 			*ft_make_str(t_specifier *spec);
/* pointer conversion */
char			*ft_make_pointer(t_specifier *spec, va_list *ap);
/* width management */
char			*ft_manage_pw(char *str, int pw, int len);
char			*ft_str_add_zeros(char *str, int n, t_specifier *spec);
char			*ft_str_add_spaces(char *str, int n);
char			*ft_str_add_left_spaces(char *str, int n);
/* general functions */
char			*ft_cage_x(size_t slen, char *str);
char			*ft_cage_X(size_t slen, char *str);
char			*ft_cage_o(size_t slen, char *str);
char			*ft_manage_flags(char *str, t_specifier *spec);
void			ft_dispatch_spec(t_specifier *spec, va_list *ap, int *counter);
void    		ft_init_fn(t_fn arr[65]);
int				ft_printf(char *fmt, ...);
#endif
