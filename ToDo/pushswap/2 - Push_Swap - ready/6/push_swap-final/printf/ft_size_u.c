/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:47:32 by cfavero           #+#    #+#             */
/*   Updated: 2018/03/20 14:23:57 by cfavero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	ft_length_u(t_flag *data, va_list *arg)
{
	if (data->val_size == 1 && data->val_conv != 'U'
			&& data->val_conv != 'O')
		return ((unsigned int)(va_arg(*arg, unsigned long long)));
	else if (data->val_size == 2 && data->val_conv != 'U'
			&& data->val_conv != 'O')
		return ((long long)((unsigned char)va_arg(*arg, int)));
	else if (data->val_size == 3 && data->val_conv != 'U'
			&& data->val_conv != 'O')
		return (((unsigned long long)(unsigned short int)va_arg(*arg, int)));
	else if (data->val_size == 6)
		return ((unsigned long long)va_arg(*arg, unsigned long long));
	else if (data->val_size == 7)
		return ((unsigned long long)va_arg(*arg, size_t));
	else if (data->val_size == 4)
		return ((uintmax_t)va_arg(*arg, uintmax_t));
	else
		return ((unsigned long)va_arg(*arg, uintmax_t));
}
