/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 19:19:36 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/07 14:22:49 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_flags(char *argument, t_arg *arg)
{
	int	i;

	i = 0;
	while (argument[i] && (argument[i] == '#' || argument[i] == '0' ||
			argument[i] == '-' || argument[i] == '+' || argument[i] == ' '))
	{
		if (argument[i] == '#')
			arg->sharp = 1;
		else if (argument[i] == '0')
			arg->zero = 1;
		else if (argument[i] == '-')
			arg->minus = 1;
		else if (argument[i] == '+')
			arg->plus = 1;
		else if (argument[i] == ' ')
			arg->space = 1;
		i++;
	}
	if (argument[i] == '\0')
		return (-1);
	return (i);
}

int		check_width(va_list ap, char *argument, t_arg *arg, int i)
{
	if (ft_strchr_count(argument, '.') > 1)
		return (-1);
	else if (argument[i] == '*' && ++i)
		arg->width = va_arg(ap, int);
	else
	{
		while (ft_isdigit(argument[i]))
		{
			arg->width = (arg->width * 10) + (argument[i] - 48);
			i++;
		}
	}
	return (i);
}

int		check_precision(va_list ap, char *argument, t_arg *arg, int i)
{
	if (argument[i] == '.')
	{
		arg->precision++;
		i++;
		if (argument[i] == '*' && ++i)
			arg->precision = va_arg(ap, int);
		else
		{
			while (ft_isdigit(argument[i]))
			{
				arg->precision = (arg->precision * 10) + (argument[i] - 48);
				i++;
			}
		}
	}
	return (i);
}
