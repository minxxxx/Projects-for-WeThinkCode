/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 14:22:00 by cfavero           #+#    #+#             */
/*   Updated: 2018/03/05 19:45:15 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_length_d(t_flag *data, va_list *arg)
{
	if (data->val_size == 2 && data->val_conv != 'D')
		return ((long long)((signed char)va_arg(*arg, int)));
	else if (data->val_size == 1 && data->val_conv != 'D')
		return ((int)(va_arg(*arg, int)));
	else if (data->val_size == 3 && data->val_conv != 'D')
		return ((long long)((short int)va_arg(*arg, int)));
	else if (data->val_size == 6)
		return ((long long)va_arg(*arg, long long));
	else if (data->val_size == 4)
		return ((intmax_t)va_arg(*arg, intmax_t));
	else if (data->val_size == 7)
		return ((long long)va_arg(*arg, size_t));
	else
		return ((long long)va_arg(*arg, long));
}
