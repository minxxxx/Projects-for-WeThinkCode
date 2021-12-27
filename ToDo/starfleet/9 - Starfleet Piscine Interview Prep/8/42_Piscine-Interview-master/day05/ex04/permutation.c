/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 16:03:36 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/09 16:03:37 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>

static void	swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return ;
}

void		permute(char *str, int left, int right)
{
	if (left != right)
	{
		for (int i = left; i <= right; i += 1)
		{
			swap((str + left), (str + i));
			permute(str, left + 1, right);
			swap((str + left), (str + i));
		}
	}
	else
		printf("%s\n", str);
	return ;
}

void		printPermutations(char *str)
{
	if (str != NULL)
		permute(str, 0, strlen(str) - 1);
	return ;
}
