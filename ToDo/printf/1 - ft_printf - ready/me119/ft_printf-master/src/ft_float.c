/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:10:28 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/13 13:23:14 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_parse_fmods(t_mods *mods, char c)
{
	if (c == 'f' || c == 'F' || c == 'e' || c == 'E' || c == 'g' || c == 'G')
	{
		if (mods->precision == -1)
			mods->precision = 6;
		if (c == 'e' || c == 'g')
			mods->exp_char = 'e';
		if (c == 'E' || c == 'G')
			mods->exp_char = 'E';
	}
	if (c == 'a' || c == 'A')
	{
		mods->base = 16;
		mods->exp_base = 2;
		mods->exp_len = 1;
		mods->exp_char = c + 15;
	}
}

static char	*ft_end_zeroes(char *str, char c, char r, t_mods *mods)
{
	char	*s;
	char	a;

	s = str;
	if (mods->flags.hash != yes)
	{
		if (str && *str)
		{
			a = *str;
			*str = 0;
			str++;
			while (*str)
				str++;
			if (s - str)
				while (*(--str) == c)
					*str = r;
			*s = a;
		}
	}
	return (s);
}

static char	*ft_ftoa_qual(long double n, t_mods *mods)
{
	char	c;
	char	*str;

	c = mods->qualifier;
	if (c == 'g' || c == 'G')
	{
		if (mods->precision == 0)
			mods->precision = 1;
		mods->sigfig = mods->precision;
		c -= ((n && n < .00001) || ft_ld_intpower(10, mods->precision)
				<= n) ? 2 : 1;
		str = ft_ftoa_handler(n, mods, c);
		str = ft_end_zeroes(ft_end_zeroes(str, '0', 0, mods), '.', 0, mods);
	}
	else
		str = ft_ftoa_handler(n, mods, c);
	return (str);
}

static char	*ft_convert_flen(va_list ap, t_mods *mods, char c)
{
	long double	n;
	char		*str;

	n = 0;
	if (mods->length == L)
		n = va_arg(ap, long double);
	else
		n = va_arg(ap, double);
	ft_parse_fmods(mods, c);
	str = (n < 0) ? ft_ftoa_qual(-n, mods) : ft_ftoa_qual(n, mods);
	if (c == 'a')
		str = ft_strjoin_free(ft_strdup("0x"), str);
	if (c == 'A')
		str = ft_strjoin_free(ft_strdup("0X"), str);
	str = (n < 0) ? ft_strjoin_free(ft_strdup("-"), str) : str;
	return (str);
}

int			ft_float(va_list ap, t_mods *mods)
{
	int		size;
	int		ret;
	char	c;
	char	*str;
	char	*mas;

	c = mods->qualifier;
	str = ft_convert_flen(ap, mods, c);
	if (c == 'g' || c == 'G')
		mods->precision = -1;
	size = ft_size(str, mods);
	mas = (char *)malloc(sizeof(char) * (size + 1));
	mods->flags.left ? ft_push_left(mods, &mas, size, str) :
		ft_push_right(mods, &mas, size, str);
	ft_putstr(mas);
	ret = ft_strlen(mas);
	free(str);
	free(mas);
	return (ret);
}
