/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 20:58:54 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/25 12:45:13 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_width(char *str, t_flag **para)
{
	int		i;

	(*para)->wid = ft_atoi(str);
	i = 0;
	while (ft_isdigit(str[i]) == 1)
		i++;
	return (i - 1);
}

static int	ft_get_precision(char *str, t_flag **para)
{
	int		i;

	i = 0;
	if (str[i] == '.')
		i++;
	(*para)->prec = 1;
	(*para)->prec_val = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]) == 1)
		i++;
	return (i - 1);
}

void		ft_verify_flags(char *format, size_t len, t_flag **para)
{
	int		i;

	i = 0;
	while (format[i] && i < (int)len)
	{
		if (format[i] != '0' && ft_isdigit(format[i]) == 1)
			i = i + ft_get_width(&format[i], &(*para));
		else if (format[i] == '.')
			i = i + ft_get_precision(&format[i], &(*para));
		else if (format[i] == '#')
			(*para)->hash = 1;
		else if (format[i] == '0')
			(*para)->zero = 1;
		else if (format[i] == '-')
			(*para)->minus = 1;
		else if (format[i] == '+')
			(*para)->plus = 1;
		else if (format[i] == ' ')
			(*para)->space = 1;
		i++;
	}
}
