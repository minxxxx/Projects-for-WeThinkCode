/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:37:46 by dkotenko          #+#    #+#             */
/*   Updated: 2018/01/12 13:37:49 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(char *str, ...)
{
	va_list		ap;
	char		*p;
	int			i;

	va_start(ap, str);
	p = str;
	i = 0;
	if (ft_strcmp("%", str) == 0)
		return (0);
	while (*p)
	{
		if (*p != '%')
		{
			write(1, p, 1);
			p++;
			i++;
		}
		else
			i += procent(&p, ap);
	}
	return (i);
}
