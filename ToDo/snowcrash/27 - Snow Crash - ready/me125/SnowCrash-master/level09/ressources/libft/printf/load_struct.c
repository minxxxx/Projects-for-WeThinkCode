/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 22:03:58 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/03 22:04:00 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void			struct_del(t_data *data)
{
	ft_memdel(((void **)&data->final_string));
	ft_memdel(((void **)&data->setting));
}

void			set_zero_data(t_data *data)
{
	if (data)
	{
		data->flag.diez = 0;
		data->flag.zero = 0;
		data->flag.plus = 0;
		data->flag.minus = 0;
		data->flag.space = 0;
		data->specifier.ll = 0;
		data->specifier.l = 0;
		data->specifier.hh = 0;
		data->specifier.h = 0;
		data->specifier.j = 0;
		data->specifier.z = 0;
		data->precision = 0;
		data->precision_null = 0;
		data->modifier = 0;
		data->len_setting = 0;
		if (data->setting)
			ft_memdel((void **)&data->setting);
		else
			data->setting = NULL;
		data->minimal_range = 0;
	}
}

void			load_struct(t_data *data)
{
	data->setting = NULL;
	data->final_len = 0;
	data->final_string = NULL;
	set_zero_data(data);
}
