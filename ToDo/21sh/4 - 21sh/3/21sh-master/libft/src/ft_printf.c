/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:13:21 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/07 14:43:31 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		store_arg(va_list ap, char *argument, t_arg *arg)
{
	int		i;

	i = ft_strlen(argument) - 1;
	arg->letter = argument[i];
	if ((i = check_flags(argument, arg)) == -1)
		return (-1);
	i = check_width(ap, argument, arg, i);
	i = check_precision(ap, argument, arg, i);
	if ((i = check_l_modifier(argument, arg, i)) == -1)
		return (-1);
	if ((i = check_h_modifier(argument, arg, i)) == -1)
		return (-1);
	if ((i = check_j_modifier(argument, arg, i)) == -1)
		return (-1);
	if ((i = check_z_modifier(argument, arg, i)) == -1)
		return (-1);
	if (argument[i] != arg->letter)
		return (-1);
	if ((arg->l + arg->ll + arg->h + arg->hh + arg->j + arg->z) > 1)
		return (-1);
	return (0);
}

void	init_struct(t_arg *arg)
{
	arg->letter = 0;
	arg->l = 0;
	arg->ll = 0;
	arg->h = 0;
	arg->hh = 0;
	arg->j = 0;
	arg->z = 0;
	arg->sharp = 0;
	arg->zero = 0;
	arg->minus = 0;
	arg->plus = 0;
	arg->space = 0;
	arg->width = 0;
	arg->precision = -1;
}

int		set_arg(va_list ap, const char *format, int start)
{
	int		i;
	int		arg_len;
	char	*argument;
	t_arg	arg;

	i = start;
	arg_len = 0;
	while (format[i])
	{
		if (ft_strchr("sSpdDioOuUxXcC%", format[i]) != NULL)
		{
			argument = ft_strsub(format, start, i - start + 1);
			arg_len = ft_strlen(argument);
			init_struct(&arg);
			store_arg(ap, argument, &arg);
			free(argument);
			print_arg(ap, &arg);
			return (arg_len);
		}
		else if (ft_strchr("0123456789 .*-+#lhzj", format[i]) == NULL)
			return (format[start] == ' ' ? 1 : 0);
		i++;
	}
	return (format[start] == ' ' ? 1 : 0);
}

int		print_format(va_list ap, const char *format)
{
	int		i;
	int		j;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			j = set_arg(ap, format, i);
			i += j;
		}
		else
		{
			ft_putchar(format[i]);
			i++;
			g_bytes++;
		}
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;

	g_bytes = 0;
	va_start(ap, format);
	print_format(ap, format);
	va_end(ap);
	return (g_bytes);
}
