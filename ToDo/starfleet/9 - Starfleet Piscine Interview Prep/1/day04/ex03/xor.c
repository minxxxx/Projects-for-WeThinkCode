/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 21:02:03 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/08 21:02:04 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*getXor(char *a, char *b)
{
	for (int i = 0; i < 6; i += 1)
		if ((a[i] == '1' && b[i] != '1') || (a[i] != '1' && b[i] == '1'))
			a[i] = '1';
		else
			a[i] = '0';
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
