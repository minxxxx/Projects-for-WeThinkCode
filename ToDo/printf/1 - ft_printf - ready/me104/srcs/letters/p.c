/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/12/06 07:52:07 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		p(va_list argp, const char *arg, int *index, t_flag *flag)
{
	char		*str;
	uintmax_t	tmp;
	void		*stack;

	(void)arg;
	(void)index;
	stack = va_arg(argp, void*);
	tmp = (unsigned long int)stack;
	str = ft_getnbr_base_ui(tmp, "0123456789abcdef");
	flag->nbr = flag->point;
	if (str[0] == '0' && flag->comma)
		flag->point += 1;
	flag->tilt = ft_strlen(str);
	flag->larg -= flag->tilt;
	flag->point -= flag->tilt;
	flag->point < 0 ? flag->point = 0 : flag->point;
	flag->larg -= flag->point;
	flag->larg -= 2;
	ft_print_memory(str, 1, flag);
	free(str);
	larg_flag_after(flag);
	return (0);
}
