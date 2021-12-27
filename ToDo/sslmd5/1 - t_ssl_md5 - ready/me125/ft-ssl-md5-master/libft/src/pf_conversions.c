/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 09:55:17 by apakhomo          #+#    #+#             */
/*   Updated: 2018/01/27 09:55:17 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				mngr_conver(t_arg *p, const char *s, size_t *i)
{
	if (conver(s[*i]))
	{
		p->conver = s[*i];
		(*i)++;
		return (0);
	}
	return (1);
}

static t_arg	big_conver(t_arg all)
{
	if (all.conver == 'O' || all.conver == 'U' || all.conver == 'C'
		|| all.conver == 'D' || all.conver == 'S')
		all.mod = L;
	if (all.conver == 'S')
		all.conver = 's';
	if (all.conver == 'D')
		all.conver = 'd';
	if (all.conver == 'U')
		all.conver = 'u';
	if (all.conver == 'C')
		all.conver = 'c';
	if (all.conver == 'O')
		all.conver = 'o';
	return (all);
}

t_arg			get_all(const char *s, size_t len)
{
	static int		(*mngr[6])(t_arg *, const char *, size_t *) = {
						mngr_add, mngr_flags, mngr_width,
						mngr_precision, mngr_mod, mngr_conver};
	t_arg			all;
	size_t			i;
	size_t			pos;

	i = 0;
	pos = 0;
	all = arg(s, len);
	while (i < 6)
	{
		if ((*mngr[i])(&all, s + 1, &pos))
		{
			all.error = 1;
			break ;
		}
		i++;
	}
	if (all.conver == 'i')
		all.conver = 'd';
	if (all.conver == 'p')
		all.mod = LL;
	return (big_conver(all));
}
