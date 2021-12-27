/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:34:06 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/17 17:20:45 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <inttypes.h>
# include <stdio.h>
# include <math.h>

# define BUFF_SIZE 4096
# define FLAG_NUMBER 5
# define TRUE 1
# define FALSE 0

/*
** ***** DATA STRUCT *******
*/

typedef	struct		s_buff
{
	char			str[BUFF_SIZE];
	size_t			size;
	int				i;
}					t_buff;

typedef	struct		s_param
{
	int				flag[FLAG_NUMBER];
	int				lmodifier;
	char			conver;
	int				base;
	int				precision;
	int				width;
	int				sign;
	int				econv;
}					t_param;

typedef	struct		s_padding
{
	int				width;
	int				precision;
	int				sign;
	int				size;
	int				arg_zero;
}					t_padding;

typedef	void		(*t_fm)(va_list *, t_param *, t_buff *);
typedef	int			(*t_fa)(va_list *, t_param *, t_buff *);
typedef	void		(*t_fb)(t_buff *, wchar_t);

enum				e_flag
{
	e_flag_hastag,
	e_flag_zero,
	e_flag_less,
	e_flag_more,
	e_flag_space,
};

enum				e_modifier
{
	e_modif_no,
	e_modif_hh,
	e_modif_h,
	e_modif_ll,
	e_modif_l,
	e_modif_j,
	e_modif_z,
};

enum				e_conv
{
	e_conv_di,
	e_conv_oux,
	e_conv_p,
	e_conv_c,
	e_conv_s,
	e_conv_lc,
	e_conv_ls,
	e_conv_percent,
};

int					ft_printf(const char *str, ...);
int					read_str(char **str, t_buff *buff, t_param *param);
void				write_buffer(t_buff *buff, int i_buff);
void				initial_param(t_param *param);
void				initial_buff(t_buff *buff);
int					verif_form(char **str, t_param *param, t_buff *buff);
void				padding_bad_conver(char **str, t_param *param,
				t_buff *buff);
void				verif_flag(char **str, t_param *param);
void				verit_fmin_width(char **str, t_param *param);
void				verif_precision(char **str, t_param *param);
void				verif_lmodifier(char **str, t_param *param);
void				verif_conversion(char **str, t_param *param);
int					assign_function(va_list *ap, t_param *param, t_buff *buff);
void				modifier_hh(va_list *ap, t_param *param, t_buff *buff);
void				print_hastag(t_buff *buff, t_param *param);
void				ft_print_charact(int i, t_buff *buff, char c);
void				padding_struct(t_padding *padding, t_param *param);

void				padding_struct_o(t_padding *padding, t_param *param);
void				padding_before_o(t_param *param, t_padding padding,
				t_buff *buff);
void				print_sign_hastag(t_param *param, t_buff *buff,
				t_padding padding);

void				padding_before(t_param *param, t_padding padding,
				t_buff *buff);
void				print_sign(t_buff *buff, t_param *param, t_padding padding);
void				str_upper(char *str[16]);
int					print_adress(va_list *ap, t_param *param, t_buff *buff);
int					size_adress(unsigned long adress);
int					print_str(va_list *ap, t_param *param, t_buff *buff);
void				add_buffer(t_buff *buff, char c);
void				ft_print_str(t_buff *buff, char *str, int precision);
int					print_percent(va_list *ap, t_param *param, t_buff *buff);

void				padding_before_str(t_param *param, int len, t_buff *buff);
int					print_char(va_list *ap, t_param *param, t_buff *buff);
void				initialise_padding(t_padding *padding, int size,
				t_param *param);

int					size_nbr(long long int arg, t_param *param);
void				print_signed(long long int arg, t_param *param,
				t_buff *buff);
int					size_intmax_nbr(intmax_t arg, t_param *param);
void				print_signed_j(intmax_t arg, t_param *param, t_buff *buff);
int					size_sizet_nbr(size_t arg, t_param *param);
void				print_unsigned_z(size_t arg, t_param *param, t_buff *buff);

int					size_u_nbr(unsigned long long int arg, t_param *param);
void				print_unsigned(unsigned long long int arg, t_param *param,
				t_buff *buff);
int					size_u_intmax_nbr(uintmax_t arg, t_param *param);
void				print_unsigned_j(uintmax_t arg, t_param *param,
				t_buff *buff);
int					size_ssizet_nbr(size_t arg, t_param *param);
void				print_signed_z(ssize_t arg, t_param *param, t_buff *buff);

int					ft_print_wchar(wchar_t wc, t_buff *buff, t_param *param);
void				write_1_byte(t_buff *buff, wchar_t wc);
void				write_2_bytes(t_buff *buff, wchar_t wc);
void				write_3_bytes(t_buff *buff, wchar_t wc);
void				write_4_bytes(t_buff *buff, wchar_t wc);
int					print_wchar(va_list *ap, t_param *param, t_buff *buff);
int					print_strwchar(va_list *ap, t_param *param, t_buff *buff);
size_t				ft_strlen_wchar(wchar_t *s);
int					ft_strlen_wchar_c(wchar_t s);
int					real_precision(wchar_t *str, int precision);

int					enum_conv(t_param *param);

int					assign_signed_modifier(va_list *ap, t_param *param,
				t_buff *buff);
void				modifier_s_no(va_list *ap, t_param *param, t_buff *buff);
void				modifier_s_hh(va_list *ap, t_param *param, t_buff *buff);
void				modifier_s_h(va_list *ap, t_param *param, t_buff *buff);
void				modifier_s_l(va_list *ap, t_param *param, t_buff *buff);
void				modifier_s_ll(va_list *ap, t_param *param, t_buff *buff);
void				modifier_s_j(va_list *ap, t_param *param, t_buff *buff);
void				modifier_s_z(va_list *ap, t_param *param, t_buff *buff);

int					assign_unsigned_modifier(va_list *ap, t_param *param,
				t_buff *buff);
void				modifier_u_no(va_list *ap, t_param *param, t_buff *buff);
void				modifier_u_hh(va_list *ap, t_param *param, t_buff *buff);
void				modifier_u_h(va_list *ap, t_param *param, t_buff *buff);
void				modifier_u_l(va_list *ap, t_param *param, t_buff *buff);
void				modifier_u_ll(va_list *ap, t_param *param, t_buff *buff);
void				modifier_u_j(va_list *ap, t_param *param, t_buff *buff);
void				modifier_u_z(va_list *ap, t_param *param, t_buff *buff);

void				print_param(t_param *param);
void				print_padding(t_padding *padding);

char				*ft_strdup(const char *s);
size_t				ft_strlen_char(const char *s);
void				ft_strcp(char *copy, const char *src);
int					abs_value(int i);

int					is_flag(char a);
int					is_number(char a);
int					is_precision(char a);
int					is_lmodifier(char a);
int					is_conversion(char a);
int					is_signed(char a);

int					is_zero_printed(t_param *param);
int					is_space_printed(t_param *param);

#endif
