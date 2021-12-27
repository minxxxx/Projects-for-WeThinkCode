/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:46:10 by dgalide           #+#    #+#             */
/*   Updated: 2016/05/01 18:20:26 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t	ft_espace(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == '\v' || s[i] == '\f' ||
			s[i] == '\r' || s[i] == ' ')
		i++;
	return (i);
}

int				ft_atoi(const char *str)
{
	size_t	i;
	char	*st;
	size_t	r;
	size_t	n;

	i = 0;
	r = 0;
	n = 0;
	if (!str)
		return (0);
	st = (char *)str;
	while (ft_espace(&st[i]))
		i++;
	if (st[i] == '+' || st[i] == '-')
	{
		if (st[i] == '-')
			n++;
		i++;
	}
	while (st[i] >= '0' && st[i] <= '9' && st)
	{
		r = r * 10 + st[i] - 48;
		i++;
	}
	return (n != 0 ? -r : r);
}

int				ft_atoi_del(char **str)
{
	size_t	i;
	size_t	r;
	size_t	n;

	i = 0;
	r = 0;
	n = 0;
	if (!(*str))
		return (0);
	while (ft_espace(&(*str)[i]))
		i++;
	if ((*str)[i] == '+' || (*str)[i] == '-')
	{
		if ((*str)[i] == '-')
			n++;
		i++;
	}
	while ((*str)[i] >= '0' && (*str)[i] <= '9' && (*str))
	{
		r = r * 10 + (*str)[i] - 48;
		i++;
	}
	ft_memdel((void **)str);
	return (n != 0 ? -r : r);
}
