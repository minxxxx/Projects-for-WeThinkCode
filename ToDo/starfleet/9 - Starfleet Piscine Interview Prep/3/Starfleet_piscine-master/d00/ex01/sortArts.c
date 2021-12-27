#include "header.h"
#include <string.h>
#include <stdlib.h>

int partition(struct s_art **arts, int p, int r)
{
	int i, j;
	struct s_art *temp, *pivot;

	pivot = arts[p];
	i = p;
	j = r;

	while (1)
	{
		while (strcmp(arts[i]->name, pivot->name) < 0)
			i++;
		while (strcmp(arts[j]->name, pivot->name) > 0)
			j--;
		if (i < j)
		{
			temp = arts[i];
			arts[i] = arts[j];
			arts[j] = temp;
			if (strcmp(arts[i]->name, arts[j]->name) == 0)
				j--;
		}
		else
			return j;
	}
}

void quicksort(struct s_art **arts, int p, int r)
{
	int q;

	if (p < r)
	{
		q = partition(arts, p, r);
		quicksort(arts, p, q);
		quicksort(arts, q + 1, r);
	}
}

void sortArts(struct s_art **arts)
{
	int r;

	r = 0;
	while (arts[r])
		r++;
	r--;
	quicksort(arts, 0, r);
}
