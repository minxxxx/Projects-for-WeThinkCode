/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_diuox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:20:14 by dkotenko          #+#    #+#             */
/*   Updated: 2018/01/13 13:20:16 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*str_diuox(char **p, char *str, int acc, va_list ap)
{
	char	modifier;

	modifier = 0;
	modif(*p, &modifier);
	if (modifier == 2 || modifier == 8)
		(*p) += 2;
	else if (modifier != 0)
		(*p)++;
	if (**p == 'd' || **p == 'i' || **p == 'u' || **p == 'o'\
	|| **p == 'x' || **p == 'X' || **p == 'D' || **p == 'O' || **p == 'U')
	{
		if (**p == 'd' || **p == 'i'\
		|| **p == 'u' || **p == 'D' || **p == 'U')
			str = diu(ap, modifier, **p);
		else if (**p == 'o' || **p == 'O')
			str = conv_o(ap, modifier, **p);
		else if (**p == 'x' || **p == 'X')
			str = conv_x(ap, modifier, **p);
		str = ft_acc_diu(str, acc);
	}
	else if (modifier == 2 || modifier == 8)
		(*p) -= 2;
	else if (modifier != 0)
		(*p)--;
	return (str);
}
