#include <stdlib.h> //malloc, free, exit...
#include "header.h"

int	**pianoDecompress(struct s_bit *bit, int l)
{
	int n;
	int **m = calloc(bit->n + 1, sizeof(int *));
	int j;
	for(int i = 0; i < bit->n; i++)
	{
		j = 0;
		m[i] = calloc(l , sizeof(int));
		n = bit->arr[i];
		for(int j = 0; n; j++)
		{
			m[i][j] = n & 1;
			n>>=1;
		}
	}
	return m;
}