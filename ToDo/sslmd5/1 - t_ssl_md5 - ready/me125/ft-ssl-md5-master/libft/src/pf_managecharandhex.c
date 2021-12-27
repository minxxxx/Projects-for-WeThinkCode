/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_managecharandhex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 10:07:54 by apakhomo          #+#    #+#             */
/*   Updated: 2018/01/27 10:07:54 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				pf_mngr_char(t_arg all, va_list arg)
{
	int		count;
	int		c;
	char	p;

	p = (all.flags & ZERO ? 48 : 32);
	count = 0;
	c = va_arg(arg, int);
	if ((all.flags & MINUS) == 0 && all.width > 1)
		count += pf_repeat(p, all.width - 1);
	count += pf_write((char *)&c, 1);
	if ((all.flags & MINUS) != 0 && all.width > 1)
		count += pf_repeat(' ', all.width - 1);
	return (count);
}

static intmax_t	s_mngr_mod(t_arg all, va_list arg)
{
	intmax_t		n;

	if (all.mod == L)
		n = va_arg(arg, long);
	else if (all.mod == LL)
		n = va_arg(arg, long long);
	else if (all.mod == J)
		n = va_arg(arg, intmax_t);
	else if (all.mod == Z)
		n = va_arg(arg, ssize_t);
	else
		n = va_arg(arg, int);
	if (all.mod == HH)
		n = (char)n;
	else if (all.mod == H)
		n = (short)n;
	return (n);
}

static int		s_mngr(t_arg all, va_list arg)
{
	char			*str;
	int				count;
	char			sign;
	intmax_t		n;

	count = 0;
	n = s_mngr_mod(all, arg);
	all.value = &n;
	if (all.flags & PLUS)
		sign = '+';
	else if (all.flags & SPACE)
		sign = ' ';
	else
		sign = 0;
	if (all.precision == 0 && n == 0)
		str = NULL;
	else
		str = pf_itoa(n, all, sign);
	count += pf_write_chunk(str, str != NULL, ft_strnlen(str, INT_MAX), all);
	return (count);
}

static intmax_t	mngr_mod_hex(t_arg all, va_list arg)
{
	intmax_t n;

	if (all.mod == L)
		n = va_arg(arg, unsigned long);
	else if (all.mod == LL)
		n = va_arg(arg, unsigned long long);
	else if (all.mod == J)
		n = va_arg(arg, uintmax_t);
	else if (all.mod == Z)
		n = va_arg(arg, size_t);
	else
		n = va_arg(arg, unsigned int);
	if (all.mod == HH)
		n = (unsigned char)n;
	else if (all.mod == H)
		n = (unsigned short)n;
	return (n);
}

int				pf_mngr_hex(t_arg all, va_list arg)
{
	uintmax_t		n;
	char			*s;
	int				count;
	int				base;
	int				size;

	if (all.conver == 'd')
		return (s_mngr(all, arg));
	base = bs(all.conver);
	count = 0;
	size = 0;
	if (all.flags & HASH || all.conver == 'p')
		size = (all.conver == 'o' ? 1 : 2);
	n = mngr_mod_hex(all, arg);
	all.value = &n;
	if ((all.precision == 0 && n == 0) || (n == 0 && all.conver == 'o'
				&& (all.flags & HASH)))
		s = NULL;
	else
		s = pf_uitoa(n, base, (all.conver == 'X' ? "0123456789ABCDEF" :
				"0123456789abcdef"), max(all.precision, ((all.flags &
				ZERO) && !(all.flags & MINUS) ?
				all.width - size : 0)));
	count += pf_write_chunk(s, s != NULL, ft_strnlen(s, INT_MAX), all);
	return (count);
}
