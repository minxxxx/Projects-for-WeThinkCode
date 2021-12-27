/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght_modif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 18:19:29 by juspende          #+#    #+#             */
/*   Updated: 2017/12/05 16:33:04 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void		length_modif_di(va_list argp, t_flag *flag, intmax_t *tmp)
{
	short	c;
	int		i;

	flag->cpy = flag->point;
	if (flag->ll != 0)
		*tmp = va_arg(argp, unsigned long int);
	else if (flag->l != 0)
		*tmp = va_arg(argp, long int);
	else if (flag->h != 0)
	{
		i = va_arg(argp, int);
		c = (short)i;
		*tmp = c;
	}
	else if (flag->hh != 0)
		*tmp = (char)va_arg(argp, int);
	else if (flag->j != 0)
		*tmp = va_arg(argp, intmax_t);
	else if (flag->z != 0)
		*tmp = va_arg(argp, size_t);
	else
		*tmp = va_arg(argp, int);
	return ;
}

void		length_modif_uox(va_list argp, t_flag *flag, uintmax_t *tmp)
{
	unsigned short		c;
	unsigned int		i;

	if (flag->ll != 0)
		*tmp = va_arg(argp, unsigned long long int);
	else if (flag->l != 0)
		*tmp = va_arg(argp, unsigned long long int);
	else if (flag->h != 0)
	{
		i = va_arg(argp, int);
		c = (unsigned short)i;
		*tmp = c;
	}
	else if (flag->hh != 0)
		*tmp = (unsigned char)va_arg(argp, unsigned int);
	else if (flag->j != 0)
		*tmp = va_arg(argp, uintmax_t);
	else if (flag->z != 0)
		*tmp = va_arg(argp, size_t);
	else
		*tmp = va_arg(argp, unsigned int);
	return ;
}
