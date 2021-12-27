/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier_oux_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:58:16 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/10 14:02:30 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	modifier_u_no(va_list *ap, t_param *param, t_buff *buff)
{
	unsigned int	arg;
	t_padding		padding;

	arg = (unsigned int)va_arg(*ap, unsigned int);
	initialise_padding(&padding, size_u_nbr((unsigned int)arg, param), param);
	if (arg == 0)
		padding.arg_zero = TRUE;
	padding_struct(&padding, param);
	padding_before(param, padding, buff);
	if (!(arg == 0 && param->precision == 0))
		print_unsigned((unsigned int)arg, param, buff);
	if (param->flag[e_flag_less])
		ft_print_charact(padding.width, buff, ' ');
}

void	modifier_u_hh(va_list *ap, t_param *param, t_buff *buff)
{
	unsigned char	arg;
	t_padding		padding;

	arg = (unsigned char)va_arg(*ap, unsigned int);
	initialise_padding(&padding, size_u_nbr((unsigned char)arg, param), param);
	if (arg == 0)
		padding.arg_zero = TRUE;
	padding_struct(&padding, param);
	padding_before(param, padding, buff);
	if (!(arg == 0 && param->precision == 0))
		print_unsigned((unsigned char)arg, param, buff);
	if (param->flag[e_flag_less])
		ft_print_charact(padding.width, buff, ' ');
}

void	modifier_u_h(va_list *ap, t_param *param, t_buff *buff)
{
	unsigned short int	arg;
	t_padding			padding;

	arg = (unsigned short int)va_arg(*ap, unsigned int);
	initialise_padding(&padding, size_u_nbr((unsigned short int)arg, param),
	param);
	if (arg == 0)
		padding.arg_zero = TRUE;
	padding_struct(&padding, param);
	padding_before(param, padding, buff);
	if (!(arg == 0 && param->precision == 0))
		print_unsigned((unsigned short int)arg, param, buff);
	if (param->flag[e_flag_less])
		ft_print_charact(padding.width, buff, ' ');
}

void	modifier_u_ll(va_list *ap, t_param *param, t_buff *buff)
{
	unsigned long long int	arg;
	t_padding				padding;

	arg = (unsigned long long int)va_arg(*ap, unsigned long long int);
	initialise_padding(&padding, size_u_nbr((unsigned long long int)arg, param),
	param);
	if (arg == 0)
		padding.arg_zero = TRUE;
	padding_struct(&padding, param);
	padding_before(param, padding, buff);
	if (!(arg == 0 && param->precision == 0))
		print_unsigned((unsigned long long int)arg, param, buff);
	if (param->flag[e_flag_less])
		ft_print_charact(padding.width, buff, ' ');
}

void	modifier_u_l(va_list *ap, t_param *param, t_buff *buff)
{
	unsigned long int	arg;
	t_padding			padding;

	arg = (unsigned long int)va_arg(*ap, unsigned long int);
	initialise_padding(&padding, size_u_nbr((unsigned long int)arg, param),
	param);
	if (arg == 0)
		padding.arg_zero = TRUE;
	padding_struct(&padding, param);
	padding_before(param, padding, buff);
	if (!(arg == 0 && param->precision == 0))
		print_unsigned((unsigned long int)arg, param, buff);
	if (param->flag[e_flag_less])
		ft_print_charact(padding.width, buff, ' ');
}
