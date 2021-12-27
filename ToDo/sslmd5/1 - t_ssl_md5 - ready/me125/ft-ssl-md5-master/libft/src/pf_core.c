/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 09:56:16 by apakhomo          #+#    #+#             */
/*   Updated: 2018/01/27 09:56:16 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	read_arg(const char *s, size_t len, int check, va_list arg)
{
	int i;

	i = -1;
	if (*s == '%' && check)
		return (pf_transform(get_all(s, len), arg, i));
	else
		return (pf_write(s, len));
}

static int	pars(const char *s, size_t *i, int *valid)
{
	if (!s[*i])
		return (1);
	while (s[*i] && validsymb(s[*i]) && !conver(s[*i]))
		(*i)++;
	if ((*valid = s[*i] && validsymb(s[*i])))
		(*i)++;
	else
		return (1);
	return (0);
}

int			pf_core(va_list arg, const char *s)
{
	size_t			a;
	size_t			b;
	int				check;
	int				i;

	a = 0;
	i = a;
	while (s[a])
	{
		b = a;
		check = 0;
		if (s[a] == '%')
		{
			a++;
			if (pars(s, &a, &check))
				continue;
		}
		else
			while (s[a] && s[a] != '%')
				a++;
		i = i + read_arg(s + b, a - b, check, arg);
	}
	return (i);
}

t_arg		arg(const char *s, size_t len)
{
	t_arg	all;

	all = (t_arg) {
		.str = (t_pfs){ .str = s, .length = len },
			.add = 0,
			.flags = 0,
			.width = 0,
			.width_add = 0,
			.precision = 0,
			.mod = NONE,
			.conver = 0,
			.error = 0
	};
	return (all);
}

t_pfs		pfs(const char *s, size_t len)
{
	return ((t_pfs) {
			.str = s,
			.length = len
			});
}
