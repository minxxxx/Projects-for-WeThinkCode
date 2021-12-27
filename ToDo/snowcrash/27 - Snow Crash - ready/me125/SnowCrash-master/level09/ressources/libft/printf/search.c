/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 02:30:29 by dgalide           #+#    #+#             */
/*   Updated: 2016/04/21 15:08:20 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int				specifier_search(char *str, t_data *data, int start)
{
	int			begin;

	begin = start;
	while (str[++start])
	{
		if (str[start] == 'd' || str[start] == 's' || \
			str[start] == 'c' || str[start] == 'S' || \
			str[start] == 'p' || str[start] == 'D' || \
			str[start] == 'i' || str[start] == 'o' || \
			str[start] == 'u' || str[start] == 'O' || \
			str[start] == 'U' || str[start] == 'x' || \
			str[start] == 'X' || str[start] == 'C' || \
			str[start] == '%')
		{
			data->modifier = str[start];
			data->setting = ft_strsub(str, begin, (start - begin) + 1);
			data->len_setting = ft_strlen(data->setting);
			return (1);
		}
	}
	return (-1);
}

static int				modifier_search(t_data *data)
{
	int			i;

	i = (ft_strlen(data->setting) - 2);
	if (data->setting[i] == 'h' && data->setting[i - 1] == 'h')
		data->specifier.hh = 1;
	else if (data->setting[i] == 'h')
		data->specifier.h = 1;
	else if (data->setting[i] == 'l' && data->setting[i - 1] == 'l')
		data->specifier.ll = 1;
	else if (data->setting[i] == 'l')
		data->specifier.l = 1;
	else if (data->setting[i] == 'j')
		data->specifier.j = 1;
	else if (data->setting[i] == 'z')
		data->specifier.z = 1;
	if (data->specifier.hh || data->specifier.ll)
		return ((check_setting(data->setting, i - 1) == 1) ? 1 : 0);
	else
		return ((check_setting(data->setting, i) == 1) ? 1 : 0);
}

static void				flag_search(t_data *data)
{
	int			i;

	i = 1;
	while (data->setting[i] && ft_is_flag(data->setting[i]))
	{
		if (data->setting[i] == '+')
			data->flag.plus = 1;
		if (data->setting[i] == '-')
			data->flag.minus = 1;
		if (data->setting[i] == '#')
			data->flag.diez = 1;
		if (data->setting[i] == '0')
			data->flag.zero = 1;
		if (data->setting[i] == ' ')
			data->flag.space = 1;
		i++;
	}
}

int						search(t_data *data, int i, const char *format)
{
	char *tmp;

	tmp = (char *)format;
	if (specifier_search(tmp, data, i) == -1)
		return (-1);
	if (modifier_search(data) == 0)
		return (-1);
	flag_search(data);
	tmp = NULL;
	return (1);
}
