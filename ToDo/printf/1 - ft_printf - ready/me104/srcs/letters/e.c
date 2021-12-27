/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/12/06 07:38:21 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		e(va_list argp, const char *arg, int *index, t_flag *flag)
{
	int		i;
	double	tmp;

	(void)index;
	larg_flag_before(flag);
	if ((tmp = va_arg(argp, double)) >= 0 && flag->pos == 1)
		ft_putchar('+', flag);
	else if (tmp >= 0 && flag->space == 1)
		ft_putchar(' ', flag);
	if ((i = 0) == 0 && tmp < 0)
		if ((tmp = -tmp) > 0)
			ft_putchar('-', flag);
	while (tmp > 10 && ++i)
		tmp = tmp / 10;
	(flag->comma != 0 ? ft_putdouble(tmp, flag->point, flag) :
	ft_putdouble(tmp, -1, flag));
	(char)arg[0] == 'e' ? ft_putstr("e+", flag) : ft_putstr("E+", flag);
	if (i < 10)
		ft_putchar('0', flag);
	larg_flag_after(flag);
	return (0);
}
