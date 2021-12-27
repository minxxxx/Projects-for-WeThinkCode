/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:18:23 by dgalide           #+#    #+#             */
/*   Updated: 2016/03/11 17:18:25 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char			*decimal_cast_handler(t_data *data, void *decimal_nb)
{
	char *str;

	str = NULL;
	if (data->specifier.h)
		str = ft_itoa((short int)decimal_nb, 10);
	else if (data->specifier.hh)
		str = ft_itoa((signed char)decimal_nb, 10);
	else if (data->specifier.l || data->modifier == 'D')
		str = ft_itoa((long)decimal_nb, 10);
	else if (data->specifier.ll)
		str = ft_itoa((long long)decimal_nb, 10);
	else if (data->specifier.j)
		str = ft_itoa((intmax_t)decimal_nb, 10);
	else if (data->specifier.z)
		str = ft_itoa((size_t)decimal_nb, 10);
	else
		str = ft_itoa((int)decimal_nb, 10);
	return (str);
}

static void			decimal_precision_handler(t_data *data, char **arg)
{
	int		i;
	int		len_arg;
	char	*tmp;

	len_arg = (int)ft_strlen(*arg);
	i = 0;
	tmp = NULL;
	if (data->precision_null == 1 && *arg[0] == '0')
		ft_memdel((void **)arg);
	else if (data->precision > len_arg || (*arg[0] == '-' &&
		data->precision >= len_arg))
	{
		data->flag.space = 0;
		tmp = ft_memset(ft_strnew((data->precision - len_arg) + 1),
			'0', (data->precision - len_arg) + 1);
		if (*arg[0] == '-')
		{
			*arg[0] = '0';
			tmp[0] = '-';
		}
		else
			tmp[data->precision - len_arg] = '\0';
		*arg = ft_strjoin_free(&tmp, arg, 1, 1);
	}
}

static void			decimal_range_handler(t_data *data, char **arg)
{
	int		len_arg;
	char	*tmp;

	tmp = NULL;
	len_arg = (int)ft_strlen(*arg);
	if (data->minimal_range > len_arg)
	{
		tmp = ft_strnew(data->minimal_range - len_arg);
		if (data->flag.zero == 1 && data->precision == 0 &&
			data->flag.minus == 0)
		{
			tmp = ft_memset(tmp, '0', (data->minimal_range - len_arg));
			sign_replace(arg, &tmp);
			*arg = ft_strjoin_free(&tmp, arg, 1, 1);
		}
		else
		{
			tmp = ft_memset(tmp, ' ', (data->minimal_range - len_arg));
			if (data->flag.minus == 1)
				*arg = ft_strjoin_free(arg, &tmp, 1, 1);
			else
				*arg = ft_strjoin_free(&tmp, arg, 1, 1);
		}
	}
}

static void			space_handler(t_data *data, char **arg)
{
	char *str;

	str = NULL;
	if (data->flag.plus || data->flag.minus || ((*arg) && (*arg)[0] == '-'))
		data->flag.space = 0;
	if (data->flag.space)
	{
		str = ft_memset(ft_strnew(1), ' ', 1);
		(*arg) = ft_strjoin_free(&str, arg, 1, 1);
	}
}

void				decimal_handler(t_data *data, va_list arg)
{
	void *i;
	char *str;

	i = va_arg(arg, void *);
	str = NULL;
	str = decimal_cast_handler(data, i);
	decimal_precision_handler(data, &str);
	if (data->flag.plus == 1)
		add_plus(&str, data);
	if (data->flag.space)
		data->minimal_range -= 1;
	decimal_range_handler(data, &str);
	space_handler(data, &str);
	data->final_len += ft_strlen(str);
	write(1, str, ft_strlen(str));
	ft_memdel((void **)&str);
}
