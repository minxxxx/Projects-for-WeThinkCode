/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 20:48:28 by dgalide           #+#    #+#             */
/*   Updated: 2016/03/05 01:27:47 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		char_handler_ext(t_data *data, int tmp, char *str)
{
	if (data->flag.minus && tmp == 1)
	{
		write(1, "\0", 1);
		write(1, str, ft_strlen(str));
	}
	else if (!(data->flag.minus) && tmp == 1)
	{
		write(1, str, ft_strlen(str));
		write(1, "\0", 1);
	}
	else
		write(1, str, ft_strlen(str));
}

void		char_handler(t_data *data, va_list arg)
{
	char	*str;
	int		tmp;

	str = ft_strnew(1);
	tmp = 0;
	str[0] = (int)va_arg(arg, void *);
	if (str[0] == 0)
	{
		tmp = 1;
		data->minimal_range -= 1;
		data->final_len += 1;
	}
	if (data->minimal_range > (int)ft_strlen((char *)str))
		generic_range_handler(data, &str);
	data->final_len += ft_strlen(str);
	char_handler_ext(data, tmp, str);
	ft_memdel((void **)&str);
}
