/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 11:59:51 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/06 15:29:30 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse_double(const char *format, t_mods *mods, int i)
{
	if (format[i] == 'h')
	{
		if (mods->length == h)
			mods->length = hh;
		else if (mods->length < h)
			mods->length = h;
	}
	else if (format[i] == 'l')
	{
		if (mods->length == l)
			mods->length = ll;
		else if (mods->length < l)
			mods->length = l;
	}
	return (i);
}

int			ft_length(const char *format, t_mods *mods)
{
	int		i;

	i = 0;
	if (format[i] == 'h' || format[i] == 'l')
		i = ft_parse_double(format, mods, i);
	else if (format[i] == 'j')
		mods->length = j;
	else if (format[i] == 'z')
		mods->length = z;
	else if (format[i] == 'L')
		mods->length = L;
	else
		return (0);
	return (1);
}
