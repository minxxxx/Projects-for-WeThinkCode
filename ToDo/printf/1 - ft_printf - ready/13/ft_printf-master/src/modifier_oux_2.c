/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier_oux_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 14:03:36 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/10 14:04:28 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	modifier_u_j(va_list *ap, t_param *param, t_buff *buff)
{
	uintmax_t	arg;
	t_padding	padding;

	arg = (uintmax_t)va_arg(*ap, uintmax_t);
	initialise_padding(&padding, size_u_intmax_nbr((uintmax_t)arg, param),
	param);
	if (arg == 0)
		padding.arg_zero = TRUE;
	padding_struct(&padding, param);
	padding_before(param, padding, buff);
	if (!(arg == 0 && param->precision == 0))
		print_unsigned_j((uintmax_t)arg, param, buff);
	if (param->flag[e_flag_less])
		ft_print_charact(padding.width, buff, ' ');
}

void	modifier_u_z(va_list *ap, t_param *param, t_buff *buff)
{
	size_t		arg;
	t_padding	padding;

	arg = (size_t)va_arg(*ap, size_t);
	initialise_padding(&padding, size_sizet_nbr((size_t)arg, param), param);
	if (arg == 0)
		padding.arg_zero = TRUE;
	padding_struct(&padding, param);
	padding_before(param, padding, buff);
	if (!(arg == 0 && param->precision == 0))
		print_unsigned_z((size_t)arg, param, buff);
	if (param->flag[e_flag_less])
		ft_print_charact(padding.width, buff, ' ');
}
