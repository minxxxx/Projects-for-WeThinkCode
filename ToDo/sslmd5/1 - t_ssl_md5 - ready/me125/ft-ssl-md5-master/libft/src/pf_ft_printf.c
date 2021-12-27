/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 09:21:35 by apakhomo          #+#    #+#             */
/*   Updated: 2018/01/27 09:21:36 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ret_transform(t_arg all, t_pf_mngr *mngr, va_list arg, int i)
{
	if (all.error)
		return (0);
	while (++i < 12)
		if (all.conver == mngr[i].conver)
			return (mngr[i].mngr(all, arg));
	return (0);
}

int			pf_transform(t_arg all, va_list arg, int i)
{
	static t_pf_mngr	(mngr[12]) = {
		{ .conver = 's', .mngr = pf_mngr_string },
		{ .conver = 'S', .mngr = pf_mngr_string },
		{ .conver = 'c', .mngr = pf_mngr_char },
		{ .conver = 'C', .mngr = pf_mngr_char },
		{ .conver = '%', .mngr = pf_mngr_percent },
		{ .conver = 'd', .mngr = pf_mngr_hex },
		{ .conver = 'x', .mngr = pf_mngr_hex },
		{ .conver = 'X', .mngr = pf_mngr_hex },
		{ .conver = 'p', .mngr = pf_mngr_hex },
		{ .conver = 'u', .mngr = pf_mngr_hex },
		{ .conver = 'U', .mngr = pf_mngr_hex },
		{ .conver = 'o', .mngr = pf_mngr_hex }
		};

	return (ret_transform(all, mngr, arg, i));
}

int			pf_write(const char *str, const size_t len)
{
	return (write(1, str, len));
}

int			pf_repeat(const char c, int len)
{
	int a;

	a = 0;
	while (a < len)
	{
		pf_write(&c, 1);
		a++;
	}
	return (a);
}

int			ft_printf(const	char *format, ...)
{
	va_list	arg;
	int		ret;

	va_start(arg, format);
	ret = pf_core(arg, format);
	va_end(arg);
	return (ret);
}
