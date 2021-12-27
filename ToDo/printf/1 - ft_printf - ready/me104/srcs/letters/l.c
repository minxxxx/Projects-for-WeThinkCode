/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/12/05 16:36:28 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		l(va_list argp, const char *arg, int *index, t_flag *flag)
{
	int		(*pointer)(va_list, const char*, int*, t_flag*);

	if (arg[1] == 'l')
	{
		*index = *index + 2;
		flag->ll = 1;
		if (arg[2] >= 'a')
			pointer = g_letter_parser[(int)arg[2] - 97];
		else
			pointer = g_letter_parser[(int)arg[2] - 97 + 32];
		return ((*pointer)(argp, &arg[2], index, flag));
	}
	else
	{
		*index = *index + 1;
		flag->l = 1;
		if (arg[1] >= 'a')
			pointer = g_letter_parser[(int)arg[1] - 97];
		else
			pointer = g_letter_parser[(int)arg[1] - 97 + 32];
		return ((*pointer)(argp, &arg[1], index, flag));
	}
}
