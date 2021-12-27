/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 19:52:54 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/25 15:38:21 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_do_conversion(va_list arg, t_flag **para, int *size)
{
	if ((*para)->c == 's')
		ft_process_s(arg, &(*para), size);
	else if ((*para)->c == 'i' || (*para)->c == 'd')
		ft_process_d(arg, &(*para), size);
	else if ((*para)->c == 'c')
		ft_process_c(arg, &(*para), size);
	else if ((*para)->c == 'p')
		ft_process_p(arg, &(*para), size);
	else if ((*para)->c == 'x')
		ft_process_x(arg, &(*para), size);
/*	else if ((*para)->c == 'o')
		ft_process_o(arg, &(*para), size);
	else if ((*para)->c == 'u')
		ft_process_u(arg, &(*para), size);*/
}

int		ft_process_format(char *str, va_list ap, int *size)
{
	static char		*conv = "sSpdDioOuUxXcCfF%";
	size_t			len;
	t_flag			*para;

	para = ft_init_flags();
	len = ft_flag_len(str);
	ft_verify_flags(str, len, &para);
	ft_check_modifiers(str, len, &para);
	para->len = len;
	para->c = str[len];
	if (str[len] != '\0' && ft_strchr(conv, str[len]) != NULL)
		ft_do_conversion(ap, &para, size);
	else if (str[len] != '\0')
	{
		ft_putchar(str[len]);
		*size = *size + 1;
	}
	ft_memdel((void **)&para);
	return (len + 2);
}

int		ft_process_printf(const char *format, va_list ap)
{
	int		size;
	size_t	i;

	i = 0;
	size = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i = i + ft_process_format((char *)&format[i + 1], ap, &size);
		else
		{
			ft_putchar(format[i]);
			i++;
			size++;
		}
	}
	return (size);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			size;

	size = 0;
	va_start(ap, format);
	size = ft_process_printf(format, ap);
	va_end(ap);
	return (size);
}
