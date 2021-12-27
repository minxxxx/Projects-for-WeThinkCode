/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:13:52 by fkuhn             #+#    #+#             */
/*   Updated: 2019/01/08 19:15:55 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char	*ft_dispatch_float(t_specifier *spec, va_list *ap)
{
	char	*str;
	int		precition;

	precition = spec->precition >= 0 ? spec->precition : 6;
	if (ft_strcmp(spec->length, "") == 0)
		str = ft_ftoa(va_arg(*ap, double), precition);
	else if (ft_strcmp(spec->length, "l") == 0)
		str = ft_ftoa(va_arg(*ap, double), precition);
	else
		str = ft_ftoa(va_arg(*ap, long double), precition);
	return (str);
}

char	*ft_dispatch_int(t_specifier *spec, va_list *ap)
{
	char	*str;

	if (ft_strcmp(spec->length, "") == 0)
		str = ft_int_to_str((int)va_arg(*ap, long), spec->precition);
	else if (ft_strcmp(spec->length, "h") == 0)
		str = ft_int_to_str((short)va_arg(*ap, long), spec->precition);
	else if (ft_strcmp(spec->length, "hh") == 0)
		str = ft_int_to_str((signed char)va_arg(*ap, long), spec->precition);
	else if (ft_strcmp(spec->length, "l") == 0)
		str = ft_int_to_str(va_arg(*ap, long), spec->precition);
	else if (ft_strcmp(spec->length, "ll") == 0)
		str = ft_int_to_str(va_arg(*ap, long long), spec->precition);
	else if (ft_strcmp(spec->length, "z") == 0)
		str = ft_int_to_str(va_arg(*ap, ssize_t), spec->precition);
	else if (ft_strcmp(spec->length, "j") == 0)
		str = ft_int_to_str(va_arg(*ap, intmax_t), spec->precition);
	else
		str = ft_itoa(0);
	return (str);
}

char	*ft_dispatch_uint(t_specifier *spec, va_list *ap)
{
	char	*str;

	if (ft_strcmp(spec->length, "") == 0)
		str = ft_uint_to_str(va_arg(*ap, unsigned int), spec);
	else if (ft_strcmp(spec->length, "h") == 0)
		str = ft_uint_to_str((unsigned short)va_arg(*ap, unsigned int), spec);
	else if (ft_strcmp(spec->length, "hh") == 0)
		str = ft_uint_to_str((unsigned char)va_arg(*ap, unsigned int), spec);
	else if (ft_strcmp(spec->length, "l") == 0)
		str = ft_uint_to_str(va_arg(*ap, unsigned long), spec);
	else if (ft_strcmp(spec->length, "ll") == 0)
		str = ft_uint_to_str(va_arg(*ap, unsigned long long), spec);
	else if (ft_strcmp(spec->length, "z") == 0)
		str = ft_uint_to_str(va_arg(*ap, size_t), spec);
	else if (ft_strcmp(spec->length, "j") == 0)
		str = ft_uint_to_str(va_arg(*ap, uintmax_t), spec);
	else
		str = ft_itoa(0);
	return (str);
}

void	ft_dispatch_spec(t_specifier *spec, va_list *ap, int *counter)
{
	char	*str;
	int		i;
	t_fn      arr[65];

	ft_init_fn(arr);
	i = 0;
	if (!(str = (*arr[spec->specifier - 'A'])(spec, ap)))
		handle_error(0, &spec);
	if (!(str = ft_manage_flags(str, spec)))
		handle_error(0, &spec);
	if (spec->specifier == 'c')
	{
		while (i < (spec->width ? spec->width : 1))
			ft_putchar(str[i++]);
		*counter += spec->width ? spec->width : 1;
	}
	else
	{
		ft_putstr(str);
		*counter += ft_strlen(str);
	}
	free(str);
	spec_del(&spec);
}