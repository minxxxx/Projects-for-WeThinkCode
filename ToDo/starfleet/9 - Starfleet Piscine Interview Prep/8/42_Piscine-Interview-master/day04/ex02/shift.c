/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 20:57:26 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/08 20:57:27 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <string.h>

char		*twoscomp(char *a)
{
	int c;

	c = 1;
	for (int i = 5; i >= 0; i--)
	{
		a[i] = (a[i] == '1') ? '0' : '1';
		if (a[i] - '0' + c == 1)
		{
			a[i] = '1';
			c = 0;
		}
		else if (a[i] - '0' + c == 2)
		{
			a[i] = '0';
			c = 1;
		}
	}
	return (a);
}

char		*rightShift(char *bin, int k)
{
	int		len;

	len = strlen(bin);
	for (int i = 0; i < k; i++)
		for (int j = len - 1; j > 0; j--)
			bin[j] = bin[j - 1];
	return (bin);
}

char		*leftShift(char *bin, int k)
{
	char	*cur;

	for (int i = 0; i < k; i++)
	{
		cur = bin + 1;
		while (*cur && *(cur + 1))
		{
			*cur = *(cur + 1);
			cur++;
		}
		*cur = '0';
	}
	return (bin);
}

int			toInt(char *bits)
{
	int		ret;
	int		sign;
	char	*tmp;

	ret = 0;
	sign = 1;
	tmp = strdup(bits);
	if (*tmp == '1')
	{
		sign = -1;
		tmp = twoscomp(tmp);
	}
	while (*tmp)
	{
		ret = ret * 2 + *tmp - '0';
		tmp += 1;
	}
	return (ret * sign);
}
