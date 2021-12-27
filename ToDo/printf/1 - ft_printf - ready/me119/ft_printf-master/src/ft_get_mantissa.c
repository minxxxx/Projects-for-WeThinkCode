/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_mantissa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 23:06:34 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/08 23:20:43 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	ft_get_mantissa(long double n, int base)
{
	long double	u;
	uintmax_t	d;

	u = 1;
	while (u < n / ft_ld_intpower(base, 8))
		u *= ft_ld_intpower(base, 8);
	while (n >= 1)
	{
		d = (uintmax_t)(n / u);
		n -= d * u;
		u /= ft_ld_intpower(base, 8);
	}
	return (n);
}
