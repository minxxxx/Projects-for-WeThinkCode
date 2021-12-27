/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 12:33:38 by thou              #+#    #+#             */
/*   Updated: 2017/03/31 14:34:02 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_persent(t_h *h)
{
	char			*dst;

	dst = ft_strdup("%");
	return (ft_printnesp(h, dst));
}

char		*ft_string(va_list arg, t_h *h)
{
	char			*str;

	if (h->l == 1)
		return (ft_wchar(arg, h));
	if (!(str = va_arg(arg, char*)))
		return (ft_strdup("(null)"));
	else
		str = ft_strdup(str);
	if (h->ps > 0 && h->ps < (int)ft_strlen(str))
		str[h->ps] = 0;
	else if (h->ps == -1)
		str[0] = 0;
	return (ft_printnesp(h, str));
}

int			wchar_to_char(unsigned char **s, wchar_t c)
{
	if (c < (1 << 7))
		*(*s)++ = (unsigned char)(c);
	else if (c < (1 << 11))
	{
		*(*s)++ = (unsigned char)((c >> 6) | 0xC0);
		*(*s)++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 16))
	{
		*(*s)++ = (unsigned char)(((c >> 12)) | 0xE0);
		*(*s)++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*(*s)++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 21))
	{
		*(*s)++ = (unsigned char)(((c >> 18)) | 0xF0);
		*(*s)++ = (unsigned char)(((c >> 12) & 0x3F) | 0x80);
		*(*s)++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*(*s)++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else
		return (-1);
	return (0);
}

char		*ft_wchar(va_list arg, t_h *h)
{
	wchar_t			*w;
	unsigned char	*str;
	unsigned char	dst[1024];
	int				i;

	if (!(w = va_arg(arg, wchar_t*)))
		return (ft_strdup("(null)"));
	str = dst;
	i = -1;
	while (w[++i])
		if (wchar_to_char(&str, w[i]) == -1)
			return (ft_strnew(0));
	*str = 0;
	if (h->ps > 0 && h->ps < (int)ft_strlen((char*)dst))
		dst[h->ps] = 0;
	else if (h->ps == -1)
		dst[0] = 0;
	return (ft_printnesp(h, ft_strdup((char*)dst)));
}

char		*ft_adresse(va_list arg, t_h *h)
{
	uintmax_t		addr;
	char			*str;

	addr = (uintmax_t)va_arg(arg, unsigned int*);
	str = ft_uimtoa_base(addr, 16, 'x');
	while ((int)ft_strlen(str) < h->ps)
		str = ft_strjoinfree2(ft_strdup("0"), str);
	if (h->ps == -1 && str[0] == '0')
		str[0] = 0;
	str = ft_strjoinfree2(ft_strdup("0x"), str);
	return (ft_printnesp(h, str));
}
