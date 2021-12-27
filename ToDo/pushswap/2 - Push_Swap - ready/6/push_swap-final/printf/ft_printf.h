/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:07:58 by cfavero           #+#    #+#             */
/*   Updated: 2018/04/26 12:12:58 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# include <limits.h>

typedef struct		s_flag
{
	int				plus;
	int				meno;
	int				zero;
	int				space;
	int				hash;
	char			numb;

	int				prec;
	int				val_prec;
	int				p;

	int				conv;
	char			val_conv;

	int				size;
	char			val_size;
}					t_flag;

int					ft_flag_s(va_list *ap, t_flag *flags);
int					ft_flag_d(va_list *ap, t_flag *flags);
int					ft_flag_o(va_list *ap, t_flag *flags);
int					ft_flag_u(va_list *ap, t_flag *flags);
int					ft_flag_x(va_list *ap, t_flag *flags);
int					ft_flag_c(va_list *ap, t_flag *flags);
t_flag				*get_list(t_flag *a);
char				*ft_unicode(wchar_t c);
char				*ft_fillstruct(const char *format, t_flag *flag);
intmax_t			ft_length_d(t_flag *data, va_list *arg);
uintmax_t			ft_length_u(t_flag *data, va_list *arg);
char				*ft_itoa_base(long long nb, const size_t base);
char				*ft_uitoa_base(unsigned long long nb, const size_t base);
char				*ft_precision_d(t_flag *flag, long long nb);
char				*ft_precision_x(t_flag *flag, unsigned long long nb);
int					ft_printf(const char *format, ...);
#endif
