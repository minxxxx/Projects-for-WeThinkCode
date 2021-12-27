/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_decimal_handler.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 15:44:30 by dgalide           #+#    #+#             */
/*   Updated: 2016/04/01 15:44:33 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*cast_handler(t_data *data, unsigned long long n)
{
	char *str;

	str = NULL;
	if (data->modifier == 'U')
		str = ft_unsigned_itoa((unsigned long int)n, 10);
	else if (data->specifier.h)
		str = ft_unsigned_itoa((unsigned short int)n, 10);
	else if (data->specifier.hh)
		str = ft_unsigned_itoa((unsigned char)n, 10);
	else if (data->specifier.l)
		str = ft_unsigned_itoa((unsigned long int)n, 10);
	else if (data->specifier.ll)
		str = ft_unsigned_itoa((unsigned long long int)n, 10);
	else if (data->specifier.j)
		str = ft_unsigned_itoa((uintmax_t)n, 10);
	else if (data->specifier.z)
		str = ft_unsigned_itoa((size_t)n, 10);
	else
		str = ft_unsigned_itoa((unsigned int)n, 10);
	return (str);
}

static void	unsigned_precision_handler(t_data *data, char **arg)
{
	char	*tmp;
	int		i;

	i = data->precision - (int)ft_strlen(*arg);
	tmp = NULL;
	if (data->precision_null && *arg[0] == '0')
		ft_memdel((void **)arg);
	if (data->precision > (int)ft_strlen(*arg))
	{
		tmp = ft_memset(ft_strnew(i), '0', i);
		*arg = ft_strjoin_free(&tmp, arg, 1, 1);
	}
}

static void	unsigned_range_handler(t_data *data, char **arg)
{
	char	*tmp;
	int		i;

	i = data->minimal_range - (int)ft_strlen(*arg);
	tmp = NULL;
	if (data->minimal_range > (int)ft_strlen(*arg))
	{
		if (data->flag.zero)
			tmp = ft_memset(ft_strnew(i), '0', i);
		else
			tmp = ft_memset(ft_strnew(i), ' ', i);
		if (data->flag.minus)
		{
			tmp = ft_memset(tmp, ' ', i);
			*arg = ft_strjoin_free(arg, &tmp, 1, 1);
		}
		else
			*arg = ft_strjoin_free(&tmp, arg, 1, 1);
	}
}

void		unsigned_decimal_handler(t_data *data, va_list arg)
{
	unsigned long long	n;
	char				*str;

	n = (unsigned long long)va_arg(arg, void *);
	str = NULL;
	str = cast_handler(data, n);
	unsigned_precision_handler(data, &str);
	unsigned_range_handler(data, &str);
	data->final_len += ft_strlen(str);
	write(1, str, ft_strlen(str));
	ft_memdel((void **)&str);
}
