/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_ls_lc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:44:04 by dkotenko          #+#    #+#             */
/*   Updated: 2018/01/28 16:44:07 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		str_lc(char **p, char flg, int width, va_list ap)
{
	char	modifier;
	int		numb;

	modifier = 0;
	numb = -1;
	modif(*p, &modifier);
	if (modifier == 2 || modifier == 8)
		(*p) += 2;
	else if (modifier != 0)
		(*p)++;
	if (**p == 'C' || ((modifier == 4) && **p == 'c'))
	{
		numb = c_unicod(ap, width, flg);
		(*p)++;
		return (numb);
	}
	else if (modifier == 2 || modifier == 8)
		(*p) -= 2;
	else if (modifier != 0)
		(*p)--;
	return (numb);
}

void	mod_ls(char **p)
{
	char	modifier;

	modifier = 0;
	modif(*p, &modifier);
	if (modifier == 2 || modifier == 8)
		(*p) += 2;
	else if (modifier != 0)
		(*p)++;
	(*p)++;
}
