/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:16:30 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/10 16:17:08 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_sign(t_mods *mods, char **mas, int i, char *str)
{
	if (str[0] == '-')
		(*mas)[i++] = '-';
	else if ((mods->flags.hash == o && str[0] != '0')
			|| mods->flags.hash == x || mods->flags.hash == X
			|| mods->flags.hash == b)
	{
		(*mas)[i++] = '0';
		if (mods->flags.hash == x)
			(*mas)[i++] = 'x';
		if (mods->flags.hash == X)
			(*mas)[i++] = 'X';
		if (mods->flags.hash == b)
			(*mas)[i++] = 'b';
	}
	else if (mods->flags.plus)
		(*mas)[i++] = '+';
	else if (mods->flags.space)
		(*mas)[i++] = ' ';
	return (i);
}

int		ft_put_content(t_mods *mods, char **mas, int i, char *str)
{
	int		j;
	int		len;
	int		precision;

	len = ft_strlen(str);
	precision = mods->precision - len;
	j = 0;
	if (str[0] == '-')
	{
		j++;
		precision++;
	}
	while (precision-- > 0)
		(*mas)[i++] = '0';
	while (str[j])
		(*mas)[i++] = str[j++];
	return (i);
}
