/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ulong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:01:38 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/12 12:31:08 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_ulong_base(unsigned long n, unsigned int base)
{
	if (n < base)
	{
		if (n < 10)
			ft_putchar(n + 48);
		else
			ft_putchar(n + 87);
	}
	else
	{
		ft_put_ulong_base(n / base, base);
		if (n % base < 10)
			ft_putchar(n % base + 48);
		else
			ft_putchar(n % base + 87);
	}
}
