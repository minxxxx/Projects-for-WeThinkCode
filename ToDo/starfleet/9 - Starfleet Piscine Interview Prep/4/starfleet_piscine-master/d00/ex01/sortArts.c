#include "header.h"
#include <string.h>

int partition(struct s_art **arts, int left, int right)
{
	struct s_art *pivot = arts[(left + right) / 2];
	struct s_art *temp;
	while (left <= right)
	{
		while(strcmp(arts[left]->name, pivot->name) < 0)
			left++;
		while(strcmp(arts[right]->name, pivot->name) > 0)
			right--;
		if (left <= right)
		{
			temp = arts[left];
			arts[left] = arts[right];
			arts[right] = temp;
			left++;
			right--;
		}
	}
	return left;
}
void quickSort(struct s_art **arts, int left, int right)
{
	if (left < right)
	{
		int pivot = partition(arts, left, right);
		quickSort(arts, left, pivot - 1);
		quickSort(arts, pivot, right);
	}
}

void  sortArts(struct s_art **arts)
{
	int i = 0;
	while (arts[i])
		i++;
	quickSort(arts, 0 , i - 1);
}