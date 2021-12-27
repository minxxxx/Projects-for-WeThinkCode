/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 20:43:11 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/08 20:43:11 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*negate(char *a)
{
	for (int i = 0; i < 4; i += 1)
		a[i] = (a[i] == '1') ? '0' : '1';
	return (a);
}

char	*getAnd(char *a, char *b)
{
	a = (a[0] == '~') ? negate(a + 1) : a;
	b = (b[0] == '~') ? negate(b + 1) : b;
	for (int i = 0; i < 4; i += 1)
		a[i] = (a[i] == '0' || b[i] == '0') ? '0' : a[i];
	return (a);
}

char	*getOr(char *a, char *b)
{
	a = (a[0] == '~') ? negate(a + 1) : a;
	b = (b[0] == '~') ? negate(b + 1) : b;
	for (int i = 0; i < 4; i += 1)
		a[i] = (a[i] == '1' || b[i] == '1') ? '1' : a[i];
	return (a);
}

int		toInt(char *bits)
{
	int	ret;

	ret = 0;
	while (*bits)
	{
		ret = ret * 2 + *bits - '0';
		bits += 1;
	}
	return (ret);
}
