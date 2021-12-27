/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sizet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:21:54 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/10 10:30:38 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		size_sizet_nbr(size_t arg, t_param *param)
{
	int i;

	i = 1;
	if (arg == 0 && param->precision == 0)
		return (0);
	while (arg / param->base)
	{
		i++;
		arg = arg / param->base;
	}
	return (i);
}

void	print_unsigned_z(size_t arg, t_param *param, t_buff *buff)
{
	int i_case;

	i_case = 0;
	param->conver == 'x' ? i_case = 32 : 1;
	if (arg / param->base != 0)
		print_unsigned_z(arg / param->base, param, buff);
	abs_value(arg % param->base) <= 9 ?
	add_buffer(buff, abs_value(arg % param->base) + '0') :
	add_buffer(buff, (abs_value(arg % param->base)) + 'A' - 10 + i_case);
}

int		size_ssizet_nbr(size_t arg, t_param *param)
{
	int i;

	i = 1;
	if (arg == 0 && param->precision == 0)
		return (0);
	while (arg / param->base)
	{
		i++;
		arg = arg / param->base;
	}
	return (i);
}

void	print_signed_z(ssize_t arg, t_param *param, t_buff *buff)
{
	int i_case;

	i_case = 0;
	param->conver == 'x' ? i_case = 32 : 1;
	if (arg / param->base != 0)
		print_signed_z(arg / param->base, param, buff);
	abs_value(arg % param->base) <= 9 ?
	add_buffer(buff, abs_value(arg % param->base) + '0') :
	add_buffer(buff, (abs_value(arg % param->base)) + 'A' - 10 + i_case);
}
