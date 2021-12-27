/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 10:05:44 by apakhomo          #+#    #+#             */
/*   Updated: 2018/01/27 10:05:45 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		uintcount(uintmax_t n, unsigned int base)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n /= base;
	}
	return (i);
}

char				*pf_uitoa(uintmax_t n, unsigned int base, const char *dig,
						size_t precision)
{
	size_t		count;
	char		*str;

	count = uintcount(n, base);
	if (count < precision)
		count = precision;
	str = ft_memalloc(count + 1);
	if (str == NULL)
		return (NULL);
	while (count > 0)
	{
		str[count - 1] = dig[n % base];
		count--;
		n /= base;
	}
	return (str);
}

static size_t		lencount(intmax_t n, int base)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n /= base;
	}
	return (i);
}

static char			*record_itoa(int count, char sign, char neg, uintmax_t v)
{
	static char	*dig = "0123456789";
	char		*str;
	int			base;

	base = 10;
	str = ft_memalloc(count + neg + 1);
	if (str == NULL)
		return (NULL);
	if (sign)
		str[0] = sign;
	while (count > 0)
	{
		str[count + neg - 1] = dig[v % base];
		count--;
		v /= base;
	}
	return (str);
}

char				*pf_itoa(intmax_t n, t_arg all, char sign)
{
	int			count;
	char		neg;
	uintmax_t	v;

	neg = (n < 0 || sign ? 1 : 0);
	count = lencount(n, 10);
	if (count < all.precision)
		count = all.precision;
	if (!(all.flags & MINUS) && (all.flags & ZERO)
			&& count < (int)all.width - neg)
	{
		count = (int)all.width - neg;
		if (all.precision > 0)
			count = all.precision;
	}
	v = (n < 0 ? -n : n);
	if (n < 0)
		sign = '-';
	return (record_itoa(count, sign, neg, v));
}
