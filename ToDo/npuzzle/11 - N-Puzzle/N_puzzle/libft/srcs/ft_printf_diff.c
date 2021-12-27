/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 13:33:44 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/04 17:10:09 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_long(const char *format, int i, va_list ap)
{
	if (format[i + 1] == 'd')
		return (ft_printf_nbr_ld(va_arg(ap, long)));
	return (0);
}

int	ft_printf_char(char c)
{
	write(1, &c, sizeof(char));
	return (1);
}

int	ft_printf_nbr(int nb)
{
	ft_putnbr(nb);
	return (ft_intlen(nb));
}

int	ft_ptintf_str(char *str)
{
	if (str == NULL)
		return (ft_printf_str("(NULL)"));
	ft_putstr(str);
	return ((int)ft_strlen(str));
}

int	ft_printf_unbr(unsigned int n)
{
	if (n >= 10)
		return (ft_printf_unbr(n / 10) + ft_printf_unbr(n % 10));
	ft_printf_char(48 + n);
	return (1);
}
