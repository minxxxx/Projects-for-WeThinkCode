/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:35:49 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/10 10:31:16 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	verif_flag(char **str, t_param *param)
{
	while (is_flag(**str))
	{
		if (**str == '#')
			param->flag[e_flag_hastag] = TRUE;
		else if (**str == '0')
			param->flag[e_flag_zero] = TRUE;
		else if (**str == '-')
			param->flag[e_flag_less] = TRUE;
		else if (**str == '+')
			param->flag[e_flag_more] = TRUE;
		else if (**str == ' ')
			param->flag[e_flag_space] = TRUE;
		*str = *str + 1;
	}
	if (param->flag[e_flag_less])
		param->flag[e_flag_zero] = FALSE;
	if (param->flag[e_flag_more])
		param->flag[e_flag_space] = FALSE;
}

void	verit_fmin_width(char **str, t_param *param)
{
	while (is_number(**str))
	{
		param->width = param->width * 10 + ((**str - 48) % 10);
		*str = *str + 1;
	}
}

void	verif_precision(char **str, t_param *param)
{
	*str = *str + 1;
	param->precision = 0;
	while (is_number(**str))
	{
		param->precision = param->precision * 10 + ((**str - 48) % 10);
		*str = *str + 1;
	}
}

void	verif_lmodifier(char **str, t_param *param)
{
	if (**str == 'h' && *(*str + 1) != 'h')
		param->lmodifier = e_modif_h;
	else if (**str == 'h' && *(*str + 1) == 'h')
	{
		param->lmodifier = e_modif_hh;
		*str = *str + 1;
	}
	else if (**str == 'l' && *(*str + 1) != 'l')
		param->lmodifier = e_modif_l;
	if (**str == 'l' && *(*str + 1) == 'l')
	{
		param->lmodifier = e_modif_ll;
		*str = *str + 1;
	}
	if (**str == 'j')
		param->lmodifier = e_modif_j;
	if (**str == 'z')
		param->lmodifier = e_modif_z;
	*str = *str + 1;
}

void	verif_conversion(char **str, t_param *param)
{
	param->conver = **str;
	*str = *str + 1;
	if (param->conver == 'd' || param->conver == 'i' || param->conver == 'u'
	|| param->conver == 'D' || param->conver == 'U')
		param->base = 10;
	else if (param->conver == 'o' || param->conver == 'O')
		param->base = 8;
	else if (param->conver == 'x' || param->conver == 'X'
	|| param->conver == 'p')
		param->base = 16;
	if (param->conver == 'D' || param->conver == 'O' || param->conver == 'U')
	{
		param->conver += 32;
		param->lmodifier = e_modif_l;
	}
	if (param->precision >= 0 && param->conver != 'c' && param->conver != 's'
		&& param->conver != 'C' && param->conver != 'S' && param->conver != '%')
		param->flag[e_flag_zero] = FALSE;
	if (param->conver == 'c' && param->lmodifier == e_modif_l)
		param->conver = 'C';
	else if (param->conver == 's' && param->lmodifier == e_modif_l)
		param->conver = 'S';
}
