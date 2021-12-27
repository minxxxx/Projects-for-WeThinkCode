/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibleSlices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 15:54:51 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/09 15:54:52 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

static void			recursiveSlices(int size, struct s_array *arr, int k)
{
	arrayAppend(arr, k);
	if (arr->sum < size)
	{
		for (int i = size; i > 0; i -= 1)
			recursiveSlices(size, arrayClone(arr), i);
	}
	else if (arr->sum == size)
		arrayPrint(arr);
	free(arr);
	return ;
}

void				printPossibleSlices(int pizzaSize)
{
	struct s_array	*arr = arrayInit();

	if (pizzaSize > 0)
	{
		for (int i = pizzaSize; i > 0; i -= 1)
			recursiveSlices(pizzaSize, arrayClone(arr), i);
	}
	free(arr);
	return ;
}
