/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 23:33:06 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/25 01:47:36 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_flag_len(char *format)
{
	static char		*flags = "#0-+ .123456789";
	size_t			len;

	len = 0;
	while (format[len] && ft_strchr(flags, format[len]) != NULL)
		len++;
	return (len);
}
