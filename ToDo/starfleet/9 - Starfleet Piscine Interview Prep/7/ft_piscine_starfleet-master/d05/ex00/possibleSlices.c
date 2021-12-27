#include "header.h"

void	recurse(struct s_array *arr, int size)
{
	struct s_array *copy;

	if (size == 0)
		arrayPrint(arr);
	else
	{
		for (int i = 0; i < size; i++)
		{
			copy = arrayClone(arr);
			arrayAppend(copy, size - i);
			recurse(copy, i);
		}
	}
}

void	printPossibleSlices(int pizzaSize)
{
	struct s_array *arr;

	arr = arrayInit();
	recurse(arr, pizzaSize);
}
