#include <stdlib.h>
#include <stdio.h>

#include "header.h"

void	print_rec(struct s_array *array, int n)
{
	struct s_array *clone;

	if (n == 0)
	{
		arrayPrint(array);
		free(array);
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		clone = arrayClone(array);
		arrayAppend(clone, i);
		print_rec(clone, n - i);
	}
}

void	printPossibleSlices(int pizzaSize)
{
	struct s_array *array = arrayInit();
	print_rec(array, pizzaSize);
}
