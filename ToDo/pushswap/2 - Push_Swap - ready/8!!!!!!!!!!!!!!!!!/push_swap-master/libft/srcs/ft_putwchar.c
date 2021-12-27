/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:22:45 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/24 16:22:46 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static wchar_t		ft_set_unicode(wchar_t c, wchar_t v, wchar_t w)
{
	v = c;
	w = c;
	if (c <= 2047)
	{
		v = (v >> 6 | 0xC0);
		c = ((c & 0x3F) | 0x80);
		c = (c << 8 | v);
	}
	else if (c <= 65535)
	{
		c = (((c & 0x3F) | 0x80) << 16);
		v = ((((v & 0xFC0) >> 6) | 0x80) << 8);
		w = ((w >> 12) | 0xE0);
		c = ((w | v) | c);
	}
	else if (c <= 1114111)
	{
		c = (((c & 0x3F) | 0x80) << 24);
		v = ((((v & 0xFC0) >> 6) | 0x80) << 16);
		w = (((w >> 12) | 0x80) << 8);
		c = (((c | v) | w) | 0xF0);
	}
	return (c);
}

void				ft_putwchar(wchar_t c)
{
	wchar_t		v;
	wchar_t		w;

	v = 0;
	w = 0;
	if (c <= 127)
		v = 1;
	else if (c <= 1114111)
	{
		if (c <= 2047)
			v = 2;
		else if (c <= 65535)
			v = 3;
		else
			v = 4;
		c = ft_set_unicode(c, v, w);
	}
	write(1, &c, v);
}
