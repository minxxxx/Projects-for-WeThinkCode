#include "header.h"

void	swap(struct s_art **art1, struct s_art **art2)
{
	struct s_art *tmp; 
	
	tmp = *art1;
	*art1 = *art2;
	*art2 = tmp;
}	

void	heapify(struct s_art **mp, int n, int i)
{
	int largest;
	int l;
	int r;

	largest = i;
	l = 2 * i + 1;
	r = 2 * i + 2;

	if (l < n && strcmp(mp[l]->name, mp[largest]->name) > 0)
		largest = l;
	if (r < n && strcmp(mp[r]->name, mp[largest]->name) > 0)
		largest = r;
	if (largest != i)
	{
		swap(mp + i, mp + largest);
		heapify(mp, n, largest);
	}
}

void heapSort(struct s_art **mp, int n)
{
	for (int i = n / 2 - 1; i >=0; i--)
		heapify(mp, n, i);
	for (int j = n - 1; j > 0; j--)
	{
		swap(mp + 0, mp + j);
		heapify(mp, j, 0);
	}
}
