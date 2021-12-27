/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibleSlices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 12:18:40 by smonroe           #+#    #+#             */
/*   Updated: 2019/01/16 22:07:41 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print(struct s_array *a, int n, int sum)
{
	if (n < 0 || a->length > sum || a->sum > sum)
		return ;
	if (n)
		arrayAppend(a, n);
	if (a->sum == sum)
		arrayPrint(a);
	for (int i = 1; i < sum; i++)
		print(arrayClone(a), i, sum);
}

void	printPossibleSlices(int n)
{
	struct s_array *a = arrayInit();
	print(a, 0, n);
	a = arrayInit();
	arrayAppend(a, n);
	arrayPrint(a);
}
