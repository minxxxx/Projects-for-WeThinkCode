/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/12/06 10:29:43 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		k(va_list argp, const char *arg, int *index, t_flag *flag)
{
	char	**tab;

	(void)argp;
	(void)arg;
	(void)index;
	(void)flag;
	if (BONUS)
	{
		tab = va_arg(argp, char**);
		ft_printtab(tab);
		return (-1);
	}
	if (flag->larg)
		*index = *index + int_len(flag->larg) - 1;
	flag->larg -= 1;
	larg_flag_before(flag);
	ft_putchar(arg[0], flag);
	larg_flag_after(flag);
	return (-1);
}
