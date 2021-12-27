/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_managestrandperc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 10:08:20 by apakhomo          #+#    #+#             */
/*   Updated: 2018/01/27 10:08:21 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			pf_mngr_percent(t_arg all, va_list arg)
{
	int		count;
	char	p;

	(void)arg;
	p = (all.flags & ZERO ? 48 : 32);
	count = 0;
	if ((all.flags & MINUS) == 0 && all.width > 1)
		count += pf_repeat(p, all.width - 1);
	count += pf_write("%", 1);
	if ((all.flags & MINUS) != 0 && all.width > 1)
		count += pf_repeat(' ', all.width - 1);
	return (count);
}

int			pf_mngr_string(t_arg all, va_list arg)
{
	char	*str;
	size_t	len;
	int		count;

	count = 0;
	str = va_arg(arg, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strnlen(str, INT_MAX);
	if (all.precision == -1)
		all.precision = INT_MAX;
	if (all.precision > (int)len)
		all.precision = len;
	count += pf_write_chunk(str, 0, all.precision, all);
	return (count);
}

static void	cast_prfx(t_arg all, int *rem, char **prfx)
{
	if ((!(all.flags & HASH) ||
			(all.value && *(uintmax_t *)all.value == 0))
			&& !((all.flags & HASH) && all.conver == 'o')
			&& !(all.conver == 'p'))
		return ;
	if (all.conver == 'x' || all.conver == 'X' ||
			all.conver == 'p')
	{
		*rem = 2;
		*prfx = (all.conver == 'X' ? "0X" : "0x");
	}
	if (all.conver == 'o')
	{
		*rem = 1;
		*prfx = "0";
	}
}

int			pf_write_chunk(const char *str, int f, size_t len, t_arg all)
{
	int		count;
	int		rem;
	char	*prfx;
	char	p;

	count = 0;
	rem = 0;
	p = (all.conver != 'd' && all.flags & ZERO ? 48 : 32);
	cast_prfx(all, &rem, &prfx);
	if (all.conver == 'o' && str && str[0] == 48)
		rem = 0;
	all.width -= rem;
	if (!(all.flags & MINUS) && all.width > len)
		count += pf_repeat(p, all.width - len);
	if (rem)
		count += pf_write(prfx, rem);
	count += pf_write(str, len);
	if ((all.flags & MINUS) && all.width > len)
		count += pf_repeat(' ', all.width - len);
	if (f)
		free((void *)str);
	return (count);
}
