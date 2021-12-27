#include "header.h"

static void	swap_art(struct s_art **arts, int i, int j)
{
	struct s_art *temp;

	temp = arts[i];
	arts[i] = arts[j];
	arts[j] = temp;
}

static int	partition(struct s_art **arts, int from, int to)
{
	int 			wall;
	struct s_art	*pivot;

	wall = from;
	pivot = arts[to];
	for (int i = from; i < to; i++)
	{
		if (strcmp(arts[i]->name, pivot->name) < 0)
		{
			swap_art(arts, i, wall);
			wall++;
		}
	}
	swap_art(arts, to, wall);
	return (wall);
}

static void	quicksort(struct s_art **arts, int from, int to)
{
	int pi;

	while (from < to)
	{
		pi = partition(arts, from, to);
		if (pi - from < to - pi)
		{
			quicksort(arts, from, pi - 1);
			from = pi + 1;
		}
		else
		{
			quicksort(arts, pi + 1, to);
			to = pi - 1;
		}
	}
}

void		sortArts(struct s_art **arts)
{
	int len;

	len = 0;
	while (arts[len])
		len++;
	quicksort(arts, 0, len - 1);
}
