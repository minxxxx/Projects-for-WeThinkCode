/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:15:52 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/13 20:15:56 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_info(va_list *arg, char **frmt)
{
	char		*tmp;
	t_info		info;
	size_t		len;

	len = 0;
	++(*frmt);
	if (**frmt != '\0')
	{
		tmp = *frmt;
		ft_initialize_struct(&info);
		ft_get_specifier(frmt, &info);
		if (!info.specifier)
			return (0);
		ft_get_flags(tmp, &info);
		ft_get_width(tmp, &info);
		ft_get_precision(tmp, &info);
		if (info.specifier != 'p')
			ft_get_modifier(tmp, &info);
		len += ft_handle_spec(arg, &info);
		++(*frmt);
	}
	return (len);
}

static int		ft_check(va_list *arg, const char *format)
{
	size_t		len;
	char		*frmt;
	char		*start;

	len = 0;
	frmt = (char *)format;
	start = (char *)format;
	while (*frmt)
	{
		if (*frmt == '%')
		{
			ft_putnstr(start, frmt - start);
			len += ft_get_info(arg, &frmt);
			start = frmt;
		}
		else if (*frmt != '\0')
		{
			len++;
			frmt++;
		}
	}
	ft_putnstr(start, frmt - start);
	return (len);
}

int				ft_printf(const char *format, ...)
{
	size_t		ret;
	va_list		arg;

	ret = 0;
	if (format)
	{
		va_start(arg, format);
		ret = ft_check(&arg, format);
		va_end(arg);
	}
	return (ret);
}
