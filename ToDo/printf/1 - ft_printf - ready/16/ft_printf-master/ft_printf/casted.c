/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:33:50 by dkotenko          #+#    #+#             */
/*   Updated: 2018/01/12 13:33:52 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long int	casted_signed(char modifier, va_list ap)
{
	long long int	ret;

	ret = 0;
	if (modifier == 0)
		ret = (int)va_arg(ap, void*);
	else if (modifier == 1)
		ret = (short int)va_arg(ap, void*);
	else if (modifier == 2)
		ret = (char)va_arg(ap, void*);
	else if (modifier == 4)
		ret = (long int)va_arg(ap, void*);
	else if (modifier == 8)
		ret = (long long int)va_arg(ap, void*);
	else if (modifier == 16)
		ret = (int64_t)va_arg(ap, void*);
	else if (modifier == 32)
		ret = (intmax_t)va_arg(ap, void*);
	else if (modifier == 64)
		ret = (size_t)va_arg(ap, void*);
	return (ret);
}

size_t			casted_unsigned(char modifier, va_list ap)
{
	size_t	ret;

	ret = 0;
	if (modifier == 0)
		ret = (unsigned int)va_arg(ap, void*);
	else if (modifier == 1)
		ret = (unsigned short int)va_arg(ap, void*);
	else if (modifier == 2)
		ret = (unsigned char)va_arg(ap, void*);
	else if (modifier == 4)
		ret = (unsigned long int)va_arg(ap, void*);
	else if (modifier == 8)
		ret = (unsigned long long int)va_arg(ap, void*);
	else if (modifier == 16)
		ret = (uint64_t)va_arg(ap, void*);
	else if (modifier == 32)
		ret = (uintmax_t)va_arg(ap, void*);
	else if (modifier == 64)
		ret = (size_t)va_arg(ap, void*);
	return (ret);
}

long long int	casted_signed_ld(char modifier, va_list ap)
{
	long long int	ret;

	ret = 0;
	if (modifier == 0)
		ret = (long int)va_arg(ap, void*);
	else if (modifier == 1)
		ret = (long int)va_arg(ap, void*);
	else if (modifier == 2)
		ret = (long int)va_arg(ap, void*);
	else if (modifier == 4)
		ret = (long int)va_arg(ap, void*);
	else if (modifier == 8)
		ret = (long long int)va_arg(ap, void*);
	else if (modifier == 16)
		ret = (int64_t)va_arg(ap, void*);
	else if (modifier == 32)
		ret = (intmax_t)va_arg(ap, void*);
	else if (modifier == 64)
		ret = (size_t)va_arg(ap, void*);
	return (ret);
}

size_t			casted_unsigned_lu(char modifier, va_list ap)
{
	size_t	ret;

	ret = 0;
	if (modifier == 0)
		ret = (unsigned long int)va_arg(ap, void*);
	else if (modifier == 1)
		ret = (unsigned long int)va_arg(ap, void*);
	else if (modifier == 2)
		ret = (unsigned long int)va_arg(ap, void*);
	else if (modifier == 4)
		ret = (unsigned long int)va_arg(ap, void*);
	else if (modifier == 8)
		ret = (unsigned long long int)va_arg(ap, void*);
	else if (modifier == 16)
		ret = (uint64_t)va_arg(ap, void*);
	else if (modifier == 32)
		ret = (uintmax_t)va_arg(ap, void*);
	else if (modifier == 64)
		ret = (size_t)va_arg(ap, void*);
	return (ret);
}
