/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 05:34:04 by dgalide           #+#    #+#             */
/*   Updated: 2016/05/04 14:52:37 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		precision_pointer_handler(char **str, t_data *data)
{
	int		n;
	char	*tmp;

	n = data->precision - (int)ft_strlen((*str));
	tmp = ft_memset(ft_strnew(n), '0', n);
	(*str) = ft_strjoin_free(&tmp, str, 1, 1);
}

static void		prefix_handler(char **str)
{
	char *tmp;

	tmp = ft_strnew(2);
	tmp[0] = '0';
	tmp[1] = 'x';
	(*str) = ft_strjoin_free(&tmp, str, 1, 1);
}

void			pointer_handler(t_data *data, va_list arg)
{
	char	*str;

	str = NULL;
	str = ft_itoa((intmax_t)va_arg(arg, intmax_t), 16);
	if (str[0] == '0' && data->precision_null == 1)
		ft_memdel((void **)&str);
	if (data->precision > (int)ft_strlen(str))
		precision_pointer_handler(&str, data);
	prefix_handler(&str);
	data->flag.zero = 0;
	if (data->minimal_range > (int)ft_strlen(str))
		generic_range_handler(data, &str);
	data->final_len += ft_strlen(str);
	write(1, str, ft_strlen(str));
	ft_memdel((void **)&str);
}
