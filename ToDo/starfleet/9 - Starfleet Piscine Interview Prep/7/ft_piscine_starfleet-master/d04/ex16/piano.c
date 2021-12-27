#include "header.h"

int **pianoDecompress(struct s_bit *bit, int l)
{
	int **matrix;

	matrix = (int**)malloc(sizeof(int*) * bit->n);
	for (int i = 0; i < bit->n; i++)
	{
		matrix[i] = (int*)calloc(l, sizeof(int));
		while (bit->arr[i])
		{
			matrix[i][(int)log2(bit->arr[i] & -bit->arr[i])] = 1;
			bit->arr[i] &= (bit->arr[i] - 1);
		}
	}
	return (matrix);
}
