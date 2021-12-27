/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fordigits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 10:01:54 by apakhomo          #+#    #+#             */
/*   Updated: 2018/01/27 10:01:54 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *s, const size_t max)
{
	size_t a;

	if (!s)
		return (0);
	a = 0;
	while (s[a] && a < max)
		a++;
	return (a);
}

int		max(int a, int b)
{
	return (a > b ? a : b);
}

int		bs(char c)
{
	if (c == 'p' || c == 'x' || c == 'X')
		return (16);
	else if (c == 'o')
		return (8);
	else
		return (10);
}

int		pf_atoi(const char *s, int allow_neg, int *result, size_t *i)
{
	int nbr;
	int neg;

	neg = (s[*i] == '-');
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (allow_neg)
			(*i)++;
		else
			return (1);
	}
	nbr = 0;
	while (ft_isdigit(s[*i]))
	{
		nbr = nbr * 10 + (s[*i] - '0');
		(*i)++;
	}
	*result = (neg ? -nbr : nbr);
	return (0);
}
