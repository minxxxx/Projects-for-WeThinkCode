/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 17:48:47 by thou              #+#    #+#             */
/*   Updated: 2017/03/27 13:56:07 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		done;
	char	*fmt;

	fmt = (char*)format;
	va_start(arg, format);
	done = ft_vfprintf(fmt, arg);
	va_end(arg);
	return (done);
}
