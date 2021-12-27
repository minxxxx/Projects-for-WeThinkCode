/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier_di_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:58:16 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/10 14:01:35 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	modifier_s_no(va_list *ap, t_param *param, t_buff *buff)
{
	int			arg;
	t_padding	padding;

	padding.sign = 0;
	arg = va_arg(*ap, int);
	initialise_padding(&padding, size_nbr((int)arg, param), param);
	if (arg < 0)
		padding.sign = -1;
	padding_struct(&padding, param);
	padding_before(param, padding, buff);
	if (!(arg == 0 && param->precision == 0))
		print_signed((int)arg, param, buff);
	if (param->flag[e_flag_less])
		ft_print_charact(padding.width, buff, ' ');
}

void	modifier_s_hh(va_list *ap, t_param *param, t_buff *buff)
{
	char		arg;
	t_padding	padding;

	padding.sign = 0;
	arg = (char)va_arg(*ap, int);
	initialise_padding(&padding, size_nbr((char)arg, param), param);
	if (arg < 0)
		padding.sign = -1;
	padding_struct(&padding, param);
	padding_before(param, padding, buff);
	if (!(arg == 0 && param->precision == 0))
		print_signed((char)arg, param, buff);
	if (param->flag[e_flag_less])
		ft_print_charact(padding.width, buff, ' ');
}

void	modifier_s_h(va_list *ap, t_param *param, t_buff *buff)
{
	short int	arg;
	t_padding	padding;

	padding.sign = 0;
	arg = (short int)va_arg(*ap, int);
	initialise_padding(&padding, size_nbr((short int)arg, param), param);
	if (arg < 0)
		padding.sign = -1;
	padding_struct(&padding, param);
	padding_before(param, padding, buff);
	if (!(arg == 0 && param->precision == 0))
		print_signed((short int)arg, param, buff);
	if (param->flag[e_flag_less])
		ft_print_charact(padding.width, buff, ' ');
}

void	modifier_s_ll(va_list *ap, t_param *param, t_buff *buff)
{
	long long int	arg;
	t_padding		padding;

	padding.sign = 0;
	arg = (long long int)va_arg(*ap, long long int);
	initialise_padding(&padding, size_nbr((long long int)arg, param), param);
	if (arg < 0)
		padding.sign = -1;
	padding_struct(&padding, param);
	padding_before(param, padding, buff);
	if (!(arg == 0 && param->precision == 0))
		print_signed((long long int)arg, param, buff);
	if (param->flag[e_flag_less])
		ft_print_charact(padding.width, buff, ' ');
}

void	modifier_s_l(va_list *ap, t_param *param, t_buff *buff)
{
	long int	arg;
	t_padding	padding;

	padding.sign = 0;
	arg = (long int)va_arg(*ap, long int);
	initialise_padding(&padding, size_nbr((long int)arg, param), param);
	if (arg < 0)
		padding.sign = -1;
	padding_struct(&padding, param);
	padding_before(param, padding, buff);
	if (!(arg == 0 && param->precision == 0))
		print_signed((long int)arg, param, buff);
	if (param->flag[e_flag_less])
		ft_print_charact(padding.width, buff, ' ');
}
