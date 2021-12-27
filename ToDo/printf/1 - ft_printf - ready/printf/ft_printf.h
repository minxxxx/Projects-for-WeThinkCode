/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 13:52:34 by sasiedu           #+#    #+#             */
/*   Updated: 2016/06/06 15:45:06 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "get_next_line.h"
# include <stdarg.h>

int				ft_printf(char *restrict format, ...);
int				ft_compare(char *str);
int				do_convert(va_list param, char *str);
int				ft_convert(va_list param, char *str);
int				ft_convert_ptr(va_list param);
int				ft_plus(va_list param, char *str);
int				do_flags(va_list param, char *str);
int				ft_minus(va_list param, char *str);
int				ft_space(va_list param, char *str);
int				ft_tag(va_list param, char *str);
int				ft_zero(va_list param, char *str);
int				ft_zero1(va_list param, int num);
int				ft_zero2(va_list param, char *str, int num);
char			*ft_retstr(va_list param, char *str);
int				ft_retint(va_list param);
int				ft_padding(va_list param, char *str);
int				ft_padding1(va_list param, char *str, int count, char *str1);
int				ft_padding2(va_list param, int count);

#endif
