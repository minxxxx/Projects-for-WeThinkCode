/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:39:57 by dkotenko          #+#    #+#             */
/*   Updated: 2018/01/12 13:39:58 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_LIBFTPRINTF_H
# define __FT_LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

long long int	casted_signed(char modifier, va_list ap);
size_t			casted_unsigned(char modifier, va_list ap);
void			flags(char *p, char *flg);
char			*ft_itoa_long(int long long n);
char			*ft_itoa_size_t(size_t n);
void			ft_swap_char(char *a, char *b);
int				mod_conv(int width, char flg, char **p, va_list ap);
int				procent(char **p, va_list ap);
char			*diu(va_list ap, char modifier, char conv);
char			*ft_acc_diu(char *str, int acc);
int				ft_printf(char *str, ...);
char			*ft_width(char *str, char flg, int width, int acc);
void			modif(char *p, char *modifier);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strnew(size_t size);
size_t			ft_strlen(char *str);
char			*ft_strchr(const char *str, int ch);
void			ft_putstr(char const *s);
char			*ft_strdup(char *src);
char			*conv_o(va_list ap, char modifier, char conv);
char			*conv_x(va_list ap, char modifier, char conv);
char			*str_diuox(char **p, char *str, int acc, va_list ap);
char			*str_s(char **p, int acc, va_list ap);
char			*str_c(char **p, va_list ap);
char			*str_null(char **p);
int				ft_strcmp(const char *s1, const char *s2);
long long int	casted_signed_ld(char modifier, va_list ap);
size_t			casted_unsigned_lu(char modifier, va_list ap);
void			ft_strdel(char **as);
int				ret_unicode(va_list ap, int acc, int width, char flg);
int				width_unicode(unsigned int *inpt, int width, int acc, char flg);
char			*str_p(char **p, char *str, int acc, va_list ap);
int				maska1(unsigned int numb, int ret);
int				maska2(unsigned int numb, int ret);
int				maska3(unsigned int numb, int ret);
int				c_unicod(va_list ap, int width, char flg);
char			*flag(char **p, char *str, int acc, char flg);
int				str_lc(char **p, char flg, int width, va_list ap);
void			mod_ls(char **p);
int				str_c_null(char flg, int width, char *str, char **p);
char			*ft_width_c(char *str, char flg, int width);
char			*flag_ox(char **p, char *str, char flg);

#endif
