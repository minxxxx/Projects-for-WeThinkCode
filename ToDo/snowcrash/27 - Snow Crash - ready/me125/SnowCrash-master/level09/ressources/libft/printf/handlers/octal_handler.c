/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 15:53:07 by dgalide           #+#    #+#             */
/*   Updated: 2016/04/07 15:53:08 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*cast_handler(t_data *data, intmax_t n)
{
	char *str;

	str = NULL;
	if (data->specifier.h)
		str = ft_unsigned_itoa((unsigned short int)n, 8);
	else if (data->specifier.hh)
		str = ft_unsigned_itoa((unsigned char)n, 8);
	else if (data->specifier.l || data->modifier == 'O')
		str = ft_unsigned_itoa((unsigned long int)n, 8);
	else if (data->specifier.ll)
		str = ft_unsigned_itoa((unsigned long long int)n, 8);
	else if (data->specifier.j)
		str = ft_unsigned_itoa((uintmax_t)n, 8);
	else if (data->specifier.z)
		str = ft_unsigned_itoa((size_t)n, 8);
	else
		str = ft_unsigned_itoa((unsigned int)n, 8);
	return (str);
}

static void	octal_diez(char **str, t_data *data)
{
	char *tmp;

	tmp = NULL;
	if (data->flag.diez)
	{
		tmp = ft_memset(ft_strnew(1), '0', 1);
		(*str) = ft_strjoin_free(&tmp, str, 1, 1);
	}
}

static void	precision_octal_handler(t_data *data, char **str)
{
	char	*tmp;
	int		n;

	n = data->precision - (int)ft_strlen((*str));
	tmp = NULL;
	if (n > 0)
	{
		tmp = ft_memset(ft_strnew(n), '0', n);
		(*str) = ft_strjoin_free(&tmp, str, 1, 1);
	}
}

static void	range_octal_handler(t_data *data, char **str)
{
	char	*tmp;
	int		n;

	n = data->minimal_range - (int)ft_strlen((*str));
	tmp = NULL;
	if (n > 0)
	{
		tmp = ft_memset(ft_strnew(n), ' ', n);
		if (data->flag.minus)
			(*str) = ft_strjoin_free(str, &tmp, 1, 1);
		else
		{
			if (data->flag.zero)
				tmp = ft_memset(tmp, '0', n);
			(*str) = ft_strjoin_free(&tmp, str, 1, 1);
		}
	}
}

void		octal_handler(t_data *data, va_list arg)
{
	char		*str;
	intmax_t	n;

	n = (intmax_t)va_arg(arg, void *);
	str = NULL;
	str = cast_handler(data, n);
	data->flag.diez = (n == 0 && !data->precision_null) ? 0 : data->flag.diez;
	if (data->precision_null && str[0] == '0')
		ft_memdel((void **)&str);
	octal_diez(&str, data);
	precision_octal_handler(data, &str);
	range_octal_handler(data, &str);
	data->final_len += ft_strlen(str);
	write(1, str, ft_strlen(str));
	ft_memdel((void **)&str);
}
