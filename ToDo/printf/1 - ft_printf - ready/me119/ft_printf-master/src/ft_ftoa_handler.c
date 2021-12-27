/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 18:08:35 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/14 15:36:03 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double	ft_round(long double n, int precision, int base)
{
	long double	m;
	long double	c;
	int			i;

	if ((i = precision) != -1)
	{
		m = ft_get_mantissa(n, base);
		c = n - m;
		while (i-- > 0)
			m *= base;
		if (ft_get_mantissa(m, base) >= .5)
			m = m - ft_get_mantissa(m, base) + 1.1;
		else
			m = m - ft_get_mantissa(m, base) + .1;
		while (++i < precision)
			m /= base;
		return (c + m);
	}
	return (n);
}

static char			*ft_mantissa(long double n, int precision, int base,
					char c)
{
	int		i;
	char	*str;

	str = ft_memalloc(sizeof(char));
	while (precision > 0 || (precision < 0 && n))
	{
		if (precision)
			precision--;
		i = n * base;
		str = ft_strjoin_free(str, ft_uitoa_base(i, base, c));
		n *= base;
		n -= i;
	}
	return (str);
}

static void			ft_init(long double *u, long double n, int base,
					char **str)
{
	(*u) = 1;
	while ((*u) < n / base)
		(*u) *= base;
	*str = ft_memalloc(sizeof(char));
}

static char			*ft_ld_ftoa(long double n, t_mods *mods, int base, char c)
{
	long double u;
	char		*str;
	uintmax_t	d;
	int			sigfig;
	int			precision;

	sigfig = mods->sigfig;
	precision = mods->precision;
	ft_init(&u, n, base, &str);
	while (sigfig && (u >= 1 || !ft_strlen(str)))
	{
		d = (uintmax_t)(n / u);
		str = ft_strjoin_free(str, ft_ftoa_base(d, base, c, 1));
		if (!(*str == '0' && ft_strlen(str) == 1))
			sigfig--;
		n -= d * u;
		u /= base;
	}
	if (sigfig && (precision > 0 || precision == -1) && n)
	{
		precision = (sigfig > 0) ? sigfig : precision;
		str = ft_strjoin_free(str, ft_strdup("."));
		str = ft_strjoin_free(str, ft_mantissa(n, precision, base, c));
	}
	return (str);
}

char				*ft_ftoa_handler(long double n, t_mods *mods, char c)
{
	char		*str;
	long double ld;
	int			i;

	if (c == 'f' || c == 'F')
		str = ft_ld_ftoa(ft_round(n, mods->precision, 10), mods, 10, c);
	else
	{
		ld = 1;
		i = 0;
		if (n >= 1)
			while (n / ld >= mods->exp_base && ++i)
				ld *= mods->exp_base;
		else
			while (n && n / ld < 1 && ++i)
				ld /= mods->exp_base;
		str = ft_ld_ftoa(ft_round(n / ld, mods->precision, mods->base),
				mods, mods->base, c);
		str = ft_strjoin_free(str, ft_memset(ft_memalloc(2),
				mods->exp_char, 1));
		str = ft_strjoin_free(str, (n >= 1 || n == 0) ? ft_strdup("+")
				: ft_strdup("-"));
		str = ft_strjoin_free(str, ft_ftoa_base(i, 10, c, mods->exp_len));
	}
	return (str);
}
