/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_manage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 09:53:14 by apakhomo          #+#    #+#             */
/*   Updated: 2018/01/27 09:53:15 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			mngr_add(t_arg *all, const char *s, size_t *i)
{
	int add;
	int t;

	t = *i;
	if (!ft_isdigit(s[*i]))
		return (0);
	if (pf_atoi(s, 0, &add, i) || s[*i] != '$')
	{
		*i = t;
		return (0);
	}
	(*i)++;
	all->add = add;
	return (0);
}

int			mngr_flags(t_arg *all, const char *s, size_t *i)
{
	char c;

	while (*i < all->str.length)
	{
		c = s[*i];
		if (flag(c))
		{
			if (c == '\'')
				all->flags |= APOST;
			else if (c == '#')
				all->flags |= HASH;
			else if (c == '-')
				all->flags |= MINUS;
			else if (c == '0')
				all->flags |= ZERO;
			else if (c == ' ')
				all->flags |= SPACE;
			else if (c == '+')
				all->flags |= PLUS;
		}
		else
			return (0);
		(*i)++;
	}
	return (1);
}

int			mngr_width(t_arg *all, const char *s, size_t *i)
{
	int width;
	int is_pos;

	if ((is_pos = (s[*i] == '*')))
		(*i)++;
	if (pf_atoi(s, 0, &width, i) && !is_pos)
		return (1);
	if (is_pos)
	{
		if (s[*i] == '$')
			(*i)++;
		else
			return (1);
		all->width_add = width;
	}
	else
		all->width = width;
	return (0);
}

int			mngr_precision(t_arg *p, const char *s, size_t *i)
{
	int precision;

	p->precision = -1;
	if (s[*i] != '.')
		return (0);
	p->precision = 0;
	(*i)++;
	if (pf_atoi(s, 0, &precision, i))
		return (1);
	p->precision = precision;
	return (0);
}

int			mngr_mod(t_arg *p, const char *s, size_t *i)
{
	t_pf_mod	mod;

	mod = WTHT;
	if (!modfc(s[*i]))
		return (0);
	else if (s[*i] == 'h')
	{
		if (s[*i + 1] == 'h' && ++(*i))
			mod = HH;
		else
			mod = H;
	}
	if (s[*i] == 'l')
	{
		if (s[*i + 1] == 'l' && ++(*i))
			mod = LL;
		else
			mod = L;
	}
	else if (s[*i] == 'z')
		mod = Z;
	else if (s[*i] == 'j')
		mod = J;
	p->mod = mod;
	return ((*i)++ & 0);
}
