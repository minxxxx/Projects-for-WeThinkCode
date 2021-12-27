/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_modifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:03:37 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/10 16:12:23 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		assign_function(va_list *ap, t_param *param, t_buff *buff)
{
	t_fa assign[8];

	enum_conv(param);
	assign[e_conv_di] = assign_signed_modifier;
	assign[e_conv_oux] = assign_unsigned_modifier;
	assign[e_conv_p] = print_adress;
	assign[e_conv_c] = print_char;
	assign[e_conv_s] = print_str;
	assign[e_conv_lc] = print_wchar;
	assign[e_conv_ls] = print_strwchar;
	assign[e_conv_percent] = print_percent;
	if (!(assign[param->econv](ap, param, buff)))
		return (0);
	return (1);
}

int		enum_conv(t_param *param)
{
	static char	conv[9][4] = {"di", "ouxX", "p", "c", "s", "C", "S",
						"%" "\0"};
	int			i;
	int			j;

	i = 0;
	while (i < 9 && conv[i])
	{
		j = 0;
		while (j < 4 && conv[i][j])
		{
			if (param->conver == conv[i][j])
			{
				param->econv = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		assign_signed_modifier(va_list *ap, t_param *param, t_buff *buff)
{
	t_fm modifier_signed[8];

	modifier_signed[e_modif_no] = modifier_s_no;
	modifier_signed[e_modif_hh] = modifier_s_hh;
	modifier_signed[e_modif_h] = modifier_s_h;
	modifier_signed[e_modif_ll] = modifier_s_ll;
	modifier_signed[e_modif_l] = modifier_s_l;
	modifier_signed[e_modif_j] = modifier_s_j;
	modifier_signed[e_modif_z] = modifier_s_z;
	modifier_signed[param->lmodifier](ap, param, buff);
	return (1);
}

int		assign_unsigned_modifier(va_list *ap, t_param *param, t_buff *buff)
{
	t_fm modifier_unsigned[8];

	modifier_unsigned[e_modif_no] = modifier_u_no;
	modifier_unsigned[e_modif_hh] = modifier_u_hh;
	modifier_unsigned[e_modif_h] = modifier_u_h;
	modifier_unsigned[e_modif_ll] = modifier_u_ll;
	modifier_unsigned[e_modif_l] = modifier_u_l;
	modifier_unsigned[e_modif_j] = modifier_u_j;
	modifier_unsigned[e_modif_z] = modifier_u_z;
	modifier_unsigned[param->lmodifier](ap, param, buff);
	return (1);
}
