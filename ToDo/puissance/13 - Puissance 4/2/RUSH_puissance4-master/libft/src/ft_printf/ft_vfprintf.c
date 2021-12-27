/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 15:02:10 by thou              #+#    #+#             */
/*   Updated: 2017/03/30 18:32:43 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	input_handlehl(char *fmt, t_h *h)
{
	if (*fmt == 'l')
	{
		if (h->l == 1)
			h->ll = 1;
		else
			h->l = 1;
	}
	else if (*fmt == 'h')
	{
		if (h->h == 1)
			h->hh = 1;
		else
			h->h = 1;
	}
	else if (*fmt == 'j')
		h->j = 1;
	else if (*fmt == 'z')
		h->z = 1;
	else if (*fmt == ' ')
		h->esp = 1;
}

void		input_handle(char **fmt, t_h *h)
{
	if (ft_strchr("hljz ", **fmt))
		input_handlehl(*fmt, h);
	else if (**fmt == '+')
		h->plus = 1;
	else if (**fmt == '-')
		h->moin = 1;
	else if (**fmt == '0')
		h->zero = 1;
	else if (**fmt == '#')
		h->ns = 1;
	else if (ft_isdigit(**fmt))
	{
		h->nb = ft_atoi(*fmt);
		while (ft_isdigit(*(*fmt + 1)))
			(*fmt)++;
	}
	else if (**fmt == '.')
	{
		h->ps = (ft_atoi((*fmt + 1)) == 0) ? -1 : ft_atoi((*fmt + 1));
		while (ft_isdigit(*(*fmt + 1)))
			(*fmt)++;
	}
	(*fmt)++;
}

void		reset_handle(t_h *h)
{
	h->l = 0;
	h->ll = 0;
	h->hh = 0;
	h->h = 0;
	h->j = 0;
	h->z = 0;
	h->esp = 0;
	h->zero = 0;
	h->plus = 0;
	h->moin = 0;
	h->ns = 0;
	h->nb = 0;
	h->isnb = 0;
	h->ps = 0;
}

static char	*ft_printp(char *fmt, va_list arg, t_h *h)
{
	if (*fmt == '%')
		return (ft_persent(h));
	if (*fmt == 's')
		return (ft_string(arg, h));
	if (*fmt == 'S')
		return (ft_wchar(arg, h));
	if (*fmt == 'p')
		return (ft_adresse(arg, h));
	if (*fmt == 'x')
		return (ft_hex(arg, h));
	if (*fmt == 'X')
		return (ft_hexup(arg, h));
	if (*fmt == 'd' || *fmt == 'i' || *fmt == 'D')
		return (ft_intdi(arg, h, *fmt));
	if (*fmt == 'c' || *fmt == 'C')
		return (ft_char(arg, h, *fmt));
	if (*fmt == 'o' || *fmt == 'O')
		return (ft_oct(arg, h, *fmt));
	if (*fmt == 'u' || *fmt == 'U')
		return (ft_unsignedint(arg, h, *fmt));
	return (ft_printnesp(h, ft_strsub(fmt, 0, 1)));
}

int			ft_vfprintf(char *fmt, va_list arg)
{
	char	*handle;
	char	*dst;
	t_h		h;

	handle = "lhjz# 0123456789+-.";
	dst = ft_strnew(0);
	h.len = 0;
	h.flag = 1;
	while (*fmt && h.flag > 0)
	{
		dst = ft_strjoinfree2(dst, ft_strsubc(fmt, '%'));
		while (*fmt && *fmt != '%')
			fmt++;
		if (*fmt == '%')
			fmt++;
		if (*fmt)
			reset_handle(&h);
		while (ft_strchr(handle, *fmt) && *fmt)
			input_handle(&fmt, &h);
		if (*fmt)
			dst = ft_strjoinfree2(dst, ft_printp(fmt++, arg, &h));
	}
	h.len += write(1, dst, ft_strlen(dst));
	free(dst);
	return (h.len);
}
