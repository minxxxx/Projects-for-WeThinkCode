/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier_p_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:36:21 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/10 14:03:27 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_adress(va_list *ap, t_param *param, t_buff *buff)
{
	int						size;
	unsigned long long int	arg;

	arg = (unsigned long long int)va_arg(*ap, unsigned long long int);
	size = size_u_nbr(arg, param);
	param->precision -= size;
	if (param->precision > 0)
		param->width = param->width - param->precision - size - 2;
	else
		param->width = param->width - size - 2;
	if (is_space_printed(param))
		ft_print_charact(param->width, buff, ' ');
	ft_print_str(buff, "0x", 2);
	if (is_zero_printed(param))
		ft_print_charact(param->width, buff, '0');
	if (param->precision > 0)
		ft_print_charact(param->precision, buff, '0');
	if (size != 0)
	{
		param->conver = 'x';
		print_unsigned(arg, param, buff);
	}
	if (param->width > 0 && param->flag[e_flag_less] == 1)
		ft_print_charact(param->width, buff, ' ');
	return (1);
}

int		print_percent(va_list *ap, t_param *param, t_buff *buff)
{
	(void)*ap;
	if (param->flag[e_flag_less] == 0)
	{
		if (param->flag[e_flag_zero] == 1)
			ft_print_charact(param->width - 1, buff, '0');
		else
			ft_print_charact(param->width - 1, buff, ' ');
	}
	ft_print_charact(1, buff, '%');
	if (param->flag[e_flag_less])
		ft_print_charact(param->width - 1, buff, ' ');
	return (1);
}

int		is_zero_printed(t_param *param)
{
	if (param->width > 0 && param->flag[e_flag_less] == 0 &&
		param->flag[e_flag_zero] == 1)
		return (1);
	return (0);
}

int		is_space_printed(t_param *param)
{
	if (param->width > 0 && param->flag[e_flag_less] == 0 &&
		param->flag[e_flag_zero] == 0)
		return (1);
	return (0);
}
