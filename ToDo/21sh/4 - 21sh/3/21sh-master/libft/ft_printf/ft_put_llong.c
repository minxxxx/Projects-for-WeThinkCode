/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_llong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:01:38 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/03 17:26:07 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_llong_base(long long n, unsigned int base)
{
	unsigned long long	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar('-');
		nb = -n;
	}
	if (nb < base)
	{
		if (nb < 10)
			ft_putchar(nb + 48);
		else
			ft_putchar(nb + 87);
	}
	else
	{
		ft_put_llong_base(nb / base, base);
		if (nb % base < 10)
			ft_putchar(nb % base + 48);
		else
			ft_putchar(nb % base + 87);
	}
}

void	ft_put_ullong_base(unsigned long long n, unsigned int base)
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
		ft_put_ullong_base(n / base, base);
		if (n % base < 10)
			ft_putchar(n % base + 48);
		else
			ft_putchar(n % base + 87);
	}
}

void	ft_put_ullong_base_upper(unsigned long long n, unsigned int base)
{
	if (n < base)
	{
		if (n < 10)
			ft_putchar(n + 48);
		else
			ft_putchar(n + 55);
	}
	else
	{
		ft_put_ullong_base_upper(n / base, base);
		if (n % base < 10)
			ft_putchar(n % base + 48);
		else
			ft_putchar(n % base + 55);
	}
}
