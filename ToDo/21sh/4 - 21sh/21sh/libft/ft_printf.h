/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 19:46:20 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/25 15:38:10 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef	struct		s_flag
{
	int				hash;
	int				zero;
	int				minus;
	int				plus;
	int				space;
	int				hh;
	int				h;
	int				l;
	int				ll;
	int				j;
	int				z;
	int				wid;
	int				prec;
	int				prec_val;
	int				len;
	char			c;
}					t_flag;

int					ft_printf(const char *format, ...);
int					ft_process_printf(const char *format, va_list ap);
int					ft_process_format(char *str, va_list ap, int *size);
size_t				ft_flag_len(char *format);
t_flag				*ft_init_flags(void);
void				ft_verify_flags(char *format, size_t len, t_flag **para);
void				ft_check_modifiers(char *format, size_t len, t_flag **para);
void				ft_do_conversion(va_list arg, t_flag **para, int *size);
void				ft_process_s(va_list arg, t_flag **para, int *size);
void				ft_printf_nbr_precision(char **str, t_flag **para, int check);
void				ft_printf_nbr_zero(char **str, t_flag **para);
void				ft_printf_nbr_minus(char **str, t_flag **para);
void				ft_printf_nbr_wid(char **str, t_flag **para);
void				ft_process_d(va_list arg, t_flag **para, int *size);
void				ft_process_c(va_list arg, t_flag **para, int *size);
void				ft_process_p(va_list arg, t_flag **para, int *size);
void				ft_printf_ptr_precision(char **str, t_flag **para);
void				ft_process_x(va_list arg, t_flag **para,  int *size);

#endif
