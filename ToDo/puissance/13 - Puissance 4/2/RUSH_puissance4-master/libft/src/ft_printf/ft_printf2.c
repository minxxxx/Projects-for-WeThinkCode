/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:04:51 by thou              #+#    #+#             */
/*   Updated: 2017/03/31 14:55:02 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_unsignedint(va_list arg, t_h *h, char c)
{
	char			*dst;

	if (c == 'U')
		h->l = 1;
	dst = ft_strnew(0);
	h->isnb = 1;
	dst = ft_strjoinfree2(dst, ft_printh(arg, h, 'u'));
	while ((int)ft_strlen(dst) < h->ps)
		dst = ft_strjoinfree2(ft_strdup("0"), dst);
	if (h->ps == -1 && dst[0] == '0')
		dst[0] = 0;
	return (ft_printnesp(h, dst));
}

char	*ft_charlc(va_list arg, t_h *h)
{
	wchar_t			w;
	unsigned char	*str;
	unsigned char	dst[5];

	if (!(w = (wchar_t)va_arg(arg, wint_t)))
	{
		h->len += 1;
		return (ft_printnesp1(h, ft_strnew(0)));
	}
	str = dst;
	if (wchar_to_char(&str, w) == -1)
	{
		h->len += 1;
		return (ft_printnesp1(h, ft_strnew(0)));
	}
	*str = 0;
	return (ft_printnesp(h, ft_strdup((char*)dst)));
}
