/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:04:19 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/06 12:07:48 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Calculates total size of string to malloc/print
** including width, plus, etc.
*/

int				ft_size(char *str, t_mods *mods)
{
	int		len;
	int		size;
	int		hash;

	len = (str[0] == '-') ? ft_strlen(str) - 1 : ft_strlen(str);
	hash = (mods->qualifier == 'o' && mods->flags.hash
			&& len >= mods->precision) ? 1 : 0;
	if ((mods->qualifier == 'x' || mods->qualifier == 'X'
				|| mods->qualifier == 'p') && mods->flags.hash)
		hash += 2;
	if (mods->width > len + hash && mods->width > mods->precision)
		size = mods->width;
	else
	{
		size = len > mods->precision ? len + hash : mods->precision + hash;
		if (mods->flags.plus || mods->flags.space || str[0] == '-')
			size++;
	}
	return (size);
}
