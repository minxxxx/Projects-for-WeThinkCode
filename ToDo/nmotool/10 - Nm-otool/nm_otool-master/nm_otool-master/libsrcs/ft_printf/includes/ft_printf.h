/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 16:59:05 by jcamhi            #+#    #+#             */
/*   Updated: 2016/02/01 10:00:20 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <assert.h>
# include <fcntl.h>
# include <stdlib.h>
# include <wchar.h>

int				ft_printf(const char *str, ...);

typedef struct	s_arg {
	int			debut;
	int			fin;
	char		*flag;
	char		conv;
	char		*str_to_print;
	char		lm[3];
	int			width;
	int			prec;
}				t_arg;

int				find_conv(const char *str, int i, t_arg *arg);
int				is_conv(const char c);
int				is_flag(const char c);
int				is_lm(const char c);
int				find_fin(const char *str, int i, t_arg *arg);
int				find_flag(const char *str, int i, t_arg *arg);
int				find_width(const char *str, int i, t_arg *arg, va_list list);
int				find_prec(const char *str, int i, t_arg *arg);
int				find_lm(const char *str, int i, t_arg *arg);
char			*init_ret(const t_arg arg, va_list list);
char			*ft_with_no_lm(const t_arg arg, va_list list);
char			*handle_flag(t_arg *arg, char *ret);
char			*handle_prec(const t_arg arg, char *ret);
char			*handle_flag_2(t_arg *arg, char *ret);
char			*handle_width(const t_arg arg, char *ret, int *n);
char			*ft_with_z(const t_arg arg, va_list list);
char			*ft_wchart_to_char(wchar_t c);
char			*ft_wchart_to_str(wchar_t *ws);
void			ft_increase(int *i, int *j);
char			*ft_alloc_str(const char *str);
char			*ft_alloc_str_with_char(int c);
int				ft_atoi(const char *str);
char			*ft_itoa_base_ll(long long nbr, int base);
char			*ft_itoa_base_ull(unsigned long long nbr, int base);
char			*ft_itoa_ptr(void *ptr);
int				ft_isdigit(int c);
void			ft_putchar(char c);
void			ft_putstr(char *s);
char			*ft_strchr(const char *s, int c);
int				ft_strequ(const char *s1, const char *s2);
char			*ft_strdup(const char *s);
char			*ft_strjoinaf12(char *s1, char *s2);
char			*ft_strjoinaf2(const char *s1, char *s2);
char			*ft_strjoinaf1(char *s1, const char *s2);
size_t			ft_strlen(const char *s);
char			*ft_strsub(char const *s, unsigned int len, size_t start);
char			*ft_strtoupper(char *s);
char			*ft_strcpy(char *dst, const char *src);
int				ft_toupper(int c);
int				after_width(const char *str, int i);
#endif
