/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 11:58:45 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/14 16:00:43 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_parse_nmods(t_mods *mods, char c, intmax_t n)
{
	if (c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'p'
			|| c == 'b')
	{
		mods->flags.plus = 0;
		mods->flags.space = 0;
		mods->flags.quote_mark = 0;
	}
	if (n == 0 && (c == 'x' || c == 'X'))
		mods->flags.hash = 0;
	if (mods->flags.hash == yes)
	{
		if (c == 'o')
			mods->flags.hash = o;
		if (c == 'x' || c == 'p')
			mods->flags.hash = x;
		if (c == 'X')
			mods->flags.hash = X;
		if (c == 'b')
			mods->flags.hash = b;
	}
}

static char	*ft_itoa_qual(intmax_t n, t_mods *mods, int flag)
{
	char	c;
	char	*str;

	c = mods->qualifier;
	if (c == 'u' || c == 'd' || c == 'i')
		str = flag ? ft_uitoa_base(n, 10, c) : ft_itoa(n);
	else if (c == 'o')
		str = ft_uitoa_base(n, 8, c);
	else if (c == 'x' || c == 'X' || c == 'p')
		str = ft_uitoa_base(n, 16, c);
	else if (c == 'b')
		str = ft_uitoa_base(n, 2, c);
	else
		return (NULL);
	if (n == 0 && mods->precision == 0)
		str[0] = '\0';
	if (mods->flags.quote_mark == 1)
		str = ft_quote_mark(str);
	return (str);
}

char		*ft_convert_ulen(va_list ap, t_mods *mods, char c)
{
	uintmax_t	n;

	n = va_arg(ap, uintmax_t);
	ft_parse_nmods(mods, c, n);
	if (mods->length == hh)
		return (ft_itoa_qual((unsigned char)n, mods, 1));
	else if (mods->length == h)
		return (ft_itoa_qual((unsigned short)n, mods, 1));
	else if (mods->length == l)
		return (ft_itoa_qual((unsigned long)n, mods, 1));
	else if (mods->length == ll)
		return (ft_itoa_qual((unsigned long long)n, mods, 1));
	else if (mods->length == j)
		return (ft_itoa_qual((uintmax_t)n, mods, 1));
	else if (mods->length == z)
		return (ft_itoa_qual((ssize_t)n, mods, 1));
	else
		return (ft_itoa_qual((unsigned int)n, mods, 1));
}

static char	*ft_parse_neg(intmax_t n, t_mods *mods)
{
	char	*str;

	if (mods->length == l)
		str = (n < 0) ? ft_itoa_qual((long)-n, mods, 1) :
			ft_itoa_qual((long)n, mods, 1);
	else if (mods->length == ll)
		str = (n < 0) ? ft_itoa_qual((long long)-n, mods, 1) :
			ft_itoa_qual((long long)n, mods, 1);
	else if (mods->length == j)
		str = (n < 0) ? ft_itoa_qual((intmax_t)-n, mods, 1) :
			ft_itoa_qual((intmax_t)n, mods, 1);
	else if (mods->length == z)
		str = (n < 0) ? ft_itoa_qual((size_t)-n, mods, 1) :
			ft_itoa_qual((size_t)n, mods, 1);
	if (n < 0)
		return (ft_strjoin_free(ft_strdup("-"), str));
	return (str);
}

char		*ft_convert_len(va_list ap, t_mods *mods, char c)
{
	intmax_t	n;

	n = va_arg(ap, intmax_t);
	ft_parse_nmods(mods, c, n);
	if (mods->length == hh)
		return (ft_itoa_qual((char)n, mods, 0));
	else if (mods->length == h)
		return (ft_itoa_qual((short)n, mods, 0));
	else if (mods->length == l || mods->length == ll || mods->length == j
			|| mods->length == z)
		return (ft_parse_neg(n, mods));
	return (ft_itoa_qual((int)n, mods, 0));
}
