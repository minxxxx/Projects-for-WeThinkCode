/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:08:14 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/12 15:38:00 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_width(const char *format, t_mods *mods, va_list ap)
{
	int		i;

	i = 0;
	if (format[i] == '*')
	{
		mods->width = va_arg(ap, int);
		if (mods->width < 0)
		{
			mods->flags.left = 1;
			mods->width *= -1;
		}
		return (1);
	}
	if (ft_isdigit(format[i]))
		mods->width = 0;
	while (ft_isdigit(format[i]))
		mods->width = mods->width * 10 + (format[i++] - '0');
	return (i);
}
