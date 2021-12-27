/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_before.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:08:11 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/10 19:36:12 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialise_padding(t_padding *padding, int size, t_param *param)
{
	padding->sign = 0;
	padding->size = size;
	padding->width = param->width - size;
	padding->precision = param->precision - size;
	if (padding->precision > 0)
		padding->width -= padding->precision;
	padding->arg_zero = FALSE;
}

void	padding_struct(t_padding *padding, t_param *param)
{
	if (param->conver == 'o')
	{
		if (padding->arg_zero == TRUE && param->precision != 0)
			param->flag[e_flag_hastag] = 0;
		if (param->flag[e_flag_hastag] == 1)
		{
			if (padding->precision < 1)
				padding->width -= 1;
			padding->precision -= 1;
		}
	}
	else
	{
		if (is_signed(param->conver))
		{
			if (padding->sign == -1 || param->flag[e_flag_more] == 1
			|| param->flag[e_flag_space] == 1)
				padding->width -= 1;
		}
		if (padding->arg_zero == TRUE)
			param->flag[e_flag_hastag] = 0;
		if (param->flag[e_flag_hastag] == 1)
			padding->width -= 2;
	}
}

void	padding_before(t_param *param, t_padding padding, t_buff *buff)
{
	if (padding.width > 0 && param->flag[e_flag_less] == 0)
	{
		if (param->flag[e_flag_zero] == TRUE)
		{
			print_sign_hastag(param, buff, padding);
			ft_print_charact(padding.width, buff, '0');
		}
		else
		{
			ft_print_charact(padding.width, buff, ' ');
			print_sign_hastag(param, buff, padding);
		}
	}
	else
		print_sign_hastag(param, buff, padding);
	if (padding.precision > 0)
		ft_print_charact(padding.precision, buff, '0');
}

void	print_sign_hastag(t_param *param, t_buff *buff, t_padding padding)
{
	if (is_signed(param->conver) == 1)
	{
		if (padding.sign == -1)
			add_buffer(buff, '-');
		else if (param->flag[e_flag_more] && padding.sign == 0)
			add_buffer(buff, '+');
		else if (param->flag[e_flag_space] && padding.sign == 0)
			add_buffer(buff, ' ');
	}
	if (param->flag[e_flag_hastag] == 1)
	{
		add_buffer(buff, '0');
		if (param->conver == 'x' || param->conver == 'X')
			add_buffer(buff, param->conver);
	}
}

void	padding_before_str(t_param *param, int len, t_buff *buff)
{
	if (param->precision == -1)
	{
		param->width = param->width - len;
		param->precision = len;
	}
	else
	{
		if (param->precision > len)
			param->width -= len;
		else
			param->width -= param->precision;
	}
	if (param->width > 0 && param->flag[e_flag_less] == 0)
	{
		if (param->flag[e_flag_zero] == TRUE)
			ft_print_charact(param->width, buff, '0');
		else
			ft_print_charact(param->width, buff, ' ');
	}
}
