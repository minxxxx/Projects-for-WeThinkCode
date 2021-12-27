/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 10:56:25 by dgalide           #+#    #+#             */
/*   Updated: 2016/04/04 10:56:27 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*cast_handler(t_data *data, intmax_t n)
{
	char *str;

	str = NULL;
	if (data->specifier.hh)
		str = ft_unsigned_itoa((unsigned char)n, 16);
	else if (data->specifier.h)
		str = ft_unsigned_itoa((unsigned short int)n, 16);
	else if (data->specifier.ll)
		str = ft_unsigned_itoa((unsigned long long int)n, 16);
	else if (data->specifier.l)
		str = ft_unsigned_itoa((unsigned long int)n, 16);
	else if (data->specifier.j)
		str = ft_unsigned_itoa((uintmax_t)n, 16);
	else if (data->specifier.z)
		str = ft_unsigned_itoa((size_t)n, 16);
	else
		str = ft_unsigned_itoa((unsigned int)n, 16);
	return (str);
}

static void		upper_case_handler(char **arg)
{
	int	i;

	i = 0;
	while ((*arg) && (*arg)[i])
	{
		if ((*arg)[i] > 96 && (*arg)[i] < 123)
			(*arg)[i] -= 32;
		i++;
	}
}

static void		range_hexadecimal_handler(t_data *data, char **arg)
{
	char	*tmp;
	int		n;

	tmp = NULL;
	n = data->minimal_range - (int)ft_strlen((*arg));
	if (n > 0)
	{
		tmp = ft_memset(ft_strnew(n), ' ', n);
		if (data->flag.minus)
			(*arg) = ft_strjoin_free(arg, &tmp, 1, 1);
		else
		{
			if (data->flag.zero == 1)
				tmp = ft_memset(tmp, '0', n);
			(*arg) = ft_strjoin_free(&tmp, arg, 1, 1);
			if (data->flag.diez && data->flag.zero)
				replace_diez(arg);
		}
	}
}

static void		precision_handler(t_data *data, char **arg, int bool_z)
{
	char	*str;
	int		n;

	str = NULL;
	n = data->precision - (int)ft_strlen((*arg));
	if (bool_z && data->precision_null)
		ft_memdel((void **)arg);
	else if (n > 0)
	{
		str = ft_memset(ft_strnew(n), '0', n);
		(*arg) = ft_strjoin_free(&str, arg, 1, 1);
	}
}

void			hexadecimal_handler(t_data *data, va_list arg)
{
	uintmax_t	n;
	int			zero_bool;
	char		*str;

	n = (uintmax_t)va_arg(arg, void *);
	str = NULL;
	str = cast_handler(data, n);
	zero_bool = (((str)[0] == '0') ? 1 : 0);
	precision_handler(data, &str, zero_bool);
	if (data->flag.diez)
		add_diez(&str, zero_bool);
	range_hexadecimal_handler(data, &str);
	if (data->modifier == 'X')
		upper_case_handler(&str);
	data->final_len += ft_strlen(str);
	write(1, str, ft_strlen(str));
	ft_memdel((void **)&str);
}
