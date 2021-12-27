/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/12/05 16:37:45 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		t(va_list argp, const char *arg, int *index, t_flag *flag)
{
	(void)argp;
	(void)arg;
	(void)index;
	(void)flag;
	if (flag->larg)
		*index = *index + int_len(flag->larg) - 1;
	flag->larg -= 1;
	larg_flag_before(flag);
	ft_putchar(arg[0], flag);
	larg_flag_after(flag);
	return (-1);
}
