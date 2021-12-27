/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uppercase_dispatch.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkuhn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:27:21 by fkuhn             #+#    #+#             */
/*   Updated: 2019/01/08 17:36:08 by fkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_upper_dispatch_uint(t_specifier *spec, va_list *ap)
{
	char	*str;

	str = ft_uint_to_str(va_arg(*ap, unsigned long), spec);
	return (str);
}

char	*ft_upper_dispatch_int(t_specifier *spec, va_list *ap)
{
	char	*str;

	str = ft_int_to_str(va_arg(*ap, long), spec->precition);
	return (str);
}

