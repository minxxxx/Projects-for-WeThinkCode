/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier_sc_cap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:40:53 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/17 17:53:17 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_strwchar(va_list *ap, t_param *param, t_buff *buff)
{
	wchar_t *str;
	int		len;

	str = (wchar_t *)va_arg(*ap, wchar_t*);
	len = 6;
	if (str != NULL && param->precision != 0)
		len = ft_strlen_wchar(str);
	if (str != NULL && param->precision > 0)
		param->precision = real_precision(str, param->precision);
	padding_before_str(param, len, buff);
	if (str == NULL)
		ft_print_str(buff, "(null)\0", param->precision);
	else if (param->precision != 0)
	{
		while (*str && param->precision >= ft_strlen_wchar_c(*str))
		{
			if (!(ft_print_wchar(*str, buff, param)))
				return (0);
			str = str + 1;
		}
	}
	if (param->flag[e_flag_less])
		ft_print_charact(param->width, buff, ' ');
	return (1);
}

int		real_precision(wchar_t *str, int precision)
{
	int wchar_precision;
	int tmp;

	wchar_precision = 0;
	tmp = 0;
	while (str)
	{
		tmp += ft_strlen_wchar_c(*str);
		if (tmp > precision)
			return (wchar_precision);
		wchar_precision = tmp;
		str = str + 1;
	}
	return (wchar_precision);
}

int		print_wchar(va_list *ap, t_param *param, t_buff *buff)
{
	wchar_t wc;
	int		real_len;

	wc = (wchar_t)va_arg(*ap, wchar_t);
	real_len = ft_strlen_wchar_c(wc);
	if (param->flag[e_flag_less] == FALSE)
	{
		if (param->flag[e_flag_zero])
			ft_print_charact(param->width - real_len, buff, '0');
		else
			ft_print_charact(param->width - real_len, buff, ' ');
	}
	if (!(ft_print_wchar(wc, buff, param)))
		return (0);
	if (param->flag[e_flag_less])
		ft_print_charact(param->width - real_len, buff, ' ');
	return (1);
}

int		ft_print_wchar(wchar_t wc, t_buff *buff, t_param *param)
{
	static int		byte[4] = {0x80, 0x800, 0x10000, 0x200000};
	int				i;
	static t_fb		w_byte[4] = {write_1_byte, write_2_bytes,
								write_3_bytes, write_4_bytes};

	i = 0;
	if (wc < 0 || (wc >= 0xd800 && wc <= 0xDFFF) || wc > 0x10FFFF)
		return (0);
	if (wc < 0x100 && MB_CUR_MAX == 1)
	{
		add_buffer(buff, wc);
		param->precision--;
		return (1);
	}
	while (i < 4)
	{
		if (wc < byte[i] && (int)MB_CUR_MAX > i)
		{
			w_byte[i](buff, wc);
			param->precision -= i + 1;
			return (1);
		}
		i++;
	}
	return (0);
}
