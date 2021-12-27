/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/12/06 08:49:58 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		n(va_list argp, const char *arg, int *index, t_flag *flag)
{
	int		*res;

	(void)arg;
	(void)flag;
	(void)index;
	res = va_arg(argp, int *);
	*res = flag->charn;
	return (0);
}
