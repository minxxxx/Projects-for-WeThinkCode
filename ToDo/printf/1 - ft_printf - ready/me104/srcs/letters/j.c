/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/12/06 10:25:45 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		j(va_list argp, const char *arg, int *index, t_flag *flag)
{
	int		(*pointer)(va_list, const char*, int*, t_flag*);

	*index = *index + 1;
	flag->j = 1;
	if (arg[1] >= 'a')
		pointer = g_letter_parser[(int)arg[1] - 97];
	else
		pointer = g_letter_parser[(int)arg[1] - 97 + 32];
	return ((*pointer)(argp, &arg[1], index, flag));
}
