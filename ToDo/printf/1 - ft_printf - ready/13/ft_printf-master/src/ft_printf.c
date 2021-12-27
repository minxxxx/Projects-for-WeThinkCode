/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:32:04 by rfibigr           #+#    #+#             */
/*   Updated: 2018/09/17 17:01:13 by rfibigr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	t_buff		buff;
	t_param		param;
	char		*str_cp;
	va_list		ap;

	if (str == NULL)
		return (0);
	str_cp = (char*)str;
	initial_buff(&buff);
	va_start(ap, str);
	while (*str_cp != '\0')
	{
		if (!(read_str(&str_cp, &buff, &param)))
			return (-1);
		if (param.conver != 0)
			if (!(assign_function(&ap, &param, &buff)))
				return (-1);
	}
	write_buffer(&buff, buff.i);
	va_end(ap);
	return (buff.size);
}
