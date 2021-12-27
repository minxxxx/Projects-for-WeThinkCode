/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:03:51 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/13 13:24:51 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_reg_i(t_mods *mods, int i, char *str, int len)
{
	if (((mods->flags.plus || mods->flags.space) && str[0] != '-')
			|| mods->flags.hash == o)
		i--;
	if (mods->precision >= len && str[0] == '-')
		i--;
	if (mods->flags.hash == x || mods->flags.hash == X)
		i -= 2;
	return (i);
}

void		ft_push_right(t_mods *mods, char **mas, int size, char *str)
{
	int		i;
	int		val;
	int		len;

	i = 0;
	if (mods->precision < 0 && mods->flags.zero)
	{
		i = ft_put_sign(mods, mas, i, str);
		if (str[0] == '-')
			str++;
		len = ft_strlen(str);
		while (i < size - len)
			(*mas)[i++] = '0';
	}
	else
	{
		len = ft_strlen(str);
		val = (len > mods->precision) ? size - len : size - mods->precision;
		while (i < val)
			(*mas)[i++] = ' ';
		i = ft_reg_i(mods, i, str, len);
		i = ft_put_sign(mods, mas, i, str);
	}
	i = ft_put_content(mods, mas, i, str);
	(*mas)[i] = '\0';
}

void		ft_push_left(t_mods *mods, char **mas, int size, char *str)
{
	int		i;

	i = ft_put_sign(mods, mas, 0, str);
	i = ft_put_content(mods, mas, i, str);
	while (i < size)
		(*mas)[i++] = ' ';
	(*mas)[i] = '\0';
}
