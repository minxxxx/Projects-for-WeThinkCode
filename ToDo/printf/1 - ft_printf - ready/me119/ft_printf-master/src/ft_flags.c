/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 11:59:04 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/12 17:43:55 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flags(const char *format, t_mods *mods)
{
	int		i;

	i = 0;
	while (format[i] == '-' || format[i] == '+' || format[i] == ' '
		|| format[i] == '#' || format[i] == '0' || format[i] == 'r'
		|| format[i] == '\'')
	{
		if (format[i] == '-')
			mods->flags.left = 1;
		else if (format[i] == '+')
			mods->flags.plus = 1;
		else if (format[i] == ' ')
			mods->flags.space = 1;
		else if (format[i] == '#')
			mods->flags.hash = yes;
		else if (format[i] == '0')
			mods->flags.zero = 1;
		else if (format[i] == 'r')
			mods->flags.unread = 1;
		else if (format[i] == '\'')
			mods->flags.quote_mark = 1;
		i++;
	}
	return (i);
}
