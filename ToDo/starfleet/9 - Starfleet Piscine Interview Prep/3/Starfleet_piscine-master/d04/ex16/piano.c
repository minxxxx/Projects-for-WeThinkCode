#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "header.h"
#include <math.h>

int **pianoDecompress(struct s_bit *bit, int l)
{
	int i = 0;
	int **ret = (int**)malloc((sizeof(int*) * bit->n) + 1);
	ret[bit->n] = 0;
	while (i < bit->n)
	{
		ret[i] = (int*)calloc(sizeof(int), l);
		ret[i][(int)log2(bit->arr[i])] = 1;
		i++;
	}
	return ret;
}
