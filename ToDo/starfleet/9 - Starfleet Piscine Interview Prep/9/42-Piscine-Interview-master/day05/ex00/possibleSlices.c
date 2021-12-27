/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibleSlices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 00:27:39 by amontano          #+#    #+#             */
/*   Updated: 2019/01/16 00:27:42 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void get_answer(int size, t_array *arr)
{
	t_array *tmp = NULL;

	if (!size && arr->sum)
		arrayPrint(arr);
	if (!size)
		return;
	for (int i = 1; i <= size; i++)
	{
		tmp = arrayClone(arr);
		arrayAppend(tmp, i);
		get_answer(size - i, tmp);
	}
}

void printPossibleSlices(int pizzaSize)
{
	get_answer(pizzaSize, arrayInit());
}