/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 20:41:38 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/08 20:41:39 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <string.h>

char		*getSum(char *a, char *b)
{
	int		carry;
	int		first;
	int		second;
	char	sum[7];

	carry = 0;
	sum[6] = '\0';
	for (int i = 5; i >= 0; i -= 1)
	{
		first = (a[i] == '1') ? 1 : 0;
		second = (b[i] == '1') ? 1 : 0;
		carry += first + second;
		sum[i] = (carry % 2) + '0';
		carry /= 2;
	}
	return (strdup(sum));
}

int			toInt(char *bits)
{
	int		ret;

	ret = 0;
	while (*bits)
	{
		ret = ret * 2 + *bits - '0';
		bits += 1;
	}
	return (ret);
}
