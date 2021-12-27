/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 10:28:40 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/12 14:20:24 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	signed_cast(va_list ap, t_arg *arg)
{
	long long	nb;

	if (arg->l || arg->letter == 'D')
		nb = va_arg(ap, long);
	else if (arg->ll)
		nb = va_arg(ap, long long);
	else if (arg->h)
		nb = (short)va_arg(ap, int);
	else if (arg->hh)
		nb = (char)va_arg(ap, int);
	else if (arg->j)
		nb = va_arg(ap, intmax_t);
	else if (arg->z)
		nb = va_arg(ap, ssize_t);
	else
		nb = va_arg(ap, int);
	print_signed_decimal(nb, arg);
}

void	unsigned_cast(va_list ap, t_arg *arg)
{
	unsigned long long	nb;

	if (arg->l || arg->letter == 'U' || arg->letter == 'O')
		nb = va_arg(ap, unsigned long);
	else if (arg->ll)
		nb = va_arg(ap, unsigned long long);
	else if (arg->h)
		nb = (unsigned short)va_arg(ap, unsigned int);
	else if (arg->hh)
		nb = (unsigned char)va_arg(ap, unsigned int);
	else if (arg->j)
		nb = va_arg(ap, uintmax_t);
	else if (arg->z)
		nb = va_arg(ap, size_t);
	else
		nb = va_arg(ap, unsigned int);
	if (arg->letter == 'u' || arg->letter == 'U')
		print_usigned_decimal(nb, arg);
	else if (arg->letter == 'o' || arg->letter == 'O')
		print_octal(nb, arg);
	else if (arg->letter == 'x' || arg->letter == 'X')
		print_hexa(nb, arg);
}

void	print_arg(va_list ap, t_arg *arg)
{
	if ((arg->letter == 'c' && arg->l) || arg->letter == 'C')
		print_wchar_t(ap, arg);
	else if (arg->letter == 'c')
		print_char(ap, arg);
	else if ((arg->letter == 's' && arg->l) || arg->letter == 'S')
		print_wchar_string(ap, arg);
	else if (arg->letter == 's')
		print_string(ap, arg);
	else if (arg->letter == 'p')
		print_address(ap, arg);
	else if (arg->letter == '%')
		print_percent(arg);
	else if (arg->letter == 'd' || arg->letter == 'D' || arg->letter == 'i')
		signed_cast(ap, arg);
	else
		unsigned_cast(ap, arg);
}
