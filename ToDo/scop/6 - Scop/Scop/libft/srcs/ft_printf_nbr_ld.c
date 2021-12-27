/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr_ld.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 13:35:55 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/04 17:11:37 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_nbr_ld(long n)
{
	if (n == -9223372036854775807)
		ft_printf_str("-9223372036854775807");
	else if (n < 0)
	{
		n *= -1;
		ft_printf_char('-');
		ft_printf_nbr_ld(n);
	}
	else if (n >= 10)
	{
		ft_printf_nbr_ld(n / 10);
		ft_printf_nbr_ld(n % 10);
	}
	else
		return (ft_printf_char(48 + n));
	return (1);
}
