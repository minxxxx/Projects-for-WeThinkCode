/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:01:45 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/06 12:01:46 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_precision(const char *format, t_mods *mods, va_list ap)
{
	int		i;

	i = 0;
	mods->precision = 0;
	if (format[++i] == '*')
	{
		mods->precision = va_arg(ap, int);
		return (2);
	}
	while (ft_isdigit(format[i]))
		mods->precision = mods->precision * 10 + (format[i++] - '0');
	return (i);
}
