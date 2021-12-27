/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 10:05:04 by jszabo            #+#    #+#             */
/*   Updated: 2018/02/24 14:11:04 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_find_length(long int value, int base, int min)
{
	int l;

	l = 0;
	if (!value)
		return (1);
	while (value > 0)
	{
		value = (value - (value % base)) / base;
		l++;
	}
	if (min)
		l++;
	return (l);
}

char		*ft_itoa_base(int value, int base)
{
	char		*ans;
	long int	tmp;
	int			min;
	int			l;

	l = 0;
	min = 0;
	if (base < 2 || base > 16)
		return (NULL);
	min = (value < 0 && base == 10) ? 1 : 0;
	tmp = (value < 0) ? ((long int)value * -1) : (long int)value;
	l = ft_find_length(tmp, base, min);
	ans = (char *)malloc(sizeof(*ans) * (l + 1));
	ans[l] = '\0';
	l--;
	ans[0] = min ? '-' : '0';
	while (l >= 0 && !(l == 0 && min))
	{
		ans[l] = (tmp % base < 10) ? (tmp % base + '0') : (tmp % base + '7');
		tmp = (tmp - (tmp % base)) / base;
		l--;
	}
	return (ans);
}
