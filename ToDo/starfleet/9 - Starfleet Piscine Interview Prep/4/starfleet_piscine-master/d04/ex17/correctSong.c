#include "header.h"
#include <stdlib.h> //malloc, free, exit...

void	correctSong(struct s_bit *bit, int l, int row, int col, int dist)
{
	if (col < l)
	{
		for (int i = row; i < row + dist && i < bit->n; i++)
			bit->arr[i] |= 1 << col;
	}
}
