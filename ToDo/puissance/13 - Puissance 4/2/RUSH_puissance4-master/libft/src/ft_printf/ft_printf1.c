/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 12:25:54 by thou              #+#    #+#             */
/*   Updated: 2017/03/31 15:12:31 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_char(va_list arg, t_h *h, char c)
{
	unsigned char	c1;
	unsigned char	str[2];

	h->ps = 0;
	if (h->l == 1 || c == 'C')
		return (ft_charlc(arg, h));
	c1 = (unsigned char)va_arg(arg, int);
	str[0] = c1;
	str[1] = 0;
	if (str[0] == 0)
	{
		h->len += 1;
		return (ft_printnesp1(h, ft_strdup((char*)str)));
	}
	return (ft_printnesp(h, ft_strdup((char*)str)));
}

char	*ft_oct(va_list arg, t_h *h, char c)
{
	char			*dst;

	if (c == 'O')
		h->l = 1;
	dst = ft_strnew(0);
	h->isnb = 1;
	dst = ft_strjoinfree2(dst, ft_printh(arg, h, 'o'));
	while ((int)ft_strlen(dst) < h->ps)
		dst = ft_strjoinfree2(ft_strdup("0"), dst);
	if (h->ps == -1 && dst[0] == '0')
		dst[0] = 0;
	if (h->ns == 1 && dst[0] != '0')
		dst = ft_strjoinfree2(ft_strdup("0"), dst);
	return (ft_printnesp(h, dst));
}

char	*ft_hex(va_list arg, t_h *h)
{
	char			*dst;

	dst = ft_strnew(0);
	h->isnb = 1;
	dst = ft_strjoinfree2(dst, ft_printh(arg, h, 'x'));
	while ((int)ft_strlen(dst) < h->ps)
		dst = ft_strjoinfree2(ft_strdup("0"), dst);
	if (h->ps == -1 && dst[0] == '0')
		dst[0] = 0;
	if (h->ns == 1 && dst[0] != '0' && dst[0] != 0)
		dst = ft_strjoinfree2(ft_strdup("0x"), dst);
	return (ft_printnesp(h, dst));
}

char	*ft_hexup(va_list arg, t_h *h)
{
	char			*dst;

	dst = ft_strnew(0);
	h->isnb = 1;
	dst = ft_strjoinfree2(dst, ft_printh(arg, h, 'X'));
	while ((int)ft_strlen(dst) < h->ps)
		dst = ft_strjoinfree2(ft_strdup("0"), dst);
	if (h->ps == -1 && dst[0] == '0')
		dst[0] = 0;
	if (h->ns == 1 && dst[0] != '0' && dst[0] != 0)
		dst = ft_strjoinfree2(ft_strdup("0X"), dst);
	return (ft_printnesp(h, dst));
}

char	*ft_intdi(va_list arg, t_h *h, char c)
{
	char			*dst;

	dst = ft_strnew(0);
	h->isnb = 1;
	if (c == 'D')
		h->l = 1;
	dst = ft_strjoinfree2(dst, ft_printh(arg, h, 'd'));
	while (dst[0] == '-' && (int)ft_strlen(dst) - 1 < h->ps)
	{
		dst[0] = '0';
		dst = ft_strjoinfree2(ft_strdup("-"), dst);
	}
	while ((int)ft_strlen(dst) < h->ps)
		dst = ft_strjoinfree2(ft_strdup("0"), dst);
	if (h->ps == -1 && dst[0] == '0')
		dst[0] = 0;
	if (h->plus == 1 && dst[0] != '-')
		dst = ft_strjoinfree2(ft_strdup("+"), dst);
	if (h->esp == 1 && dst[0] != '+' && dst[0] != '-')
		dst = ft_strjoinfree2(ft_strdup(" "), dst);
	return (ft_printnesp(h, dst));
}
