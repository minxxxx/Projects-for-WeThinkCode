/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_modifiers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 23:15:12 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/25 00:42:20 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_modifiers(char *format, size_t len, t_flag **para)
{
	size_t	i;

	i = 0;
	while (format[i] && i < len)
	{
		if (format[i] == 'h' && format[i + 1] && format[i + 1] == 'h')
		{
			(*para)->hh = 1;
			i++;
		}
		else if (format[i] == 'l' && format[i + 1] && format[i + 1] == 'l')
		{
			(*para)->ll = 1;
			i++;
		}
		else if (format[i] == 'h')
			(*para)->h = 1;
		else if (format[i] == 'l')
			(*para)->l = 1;
		else if (format[i] == 'j')
			(*para)->j = 1;
		else if (format[i] == 'z')
			(*para)->z = 1;
		i++;
	}
}
