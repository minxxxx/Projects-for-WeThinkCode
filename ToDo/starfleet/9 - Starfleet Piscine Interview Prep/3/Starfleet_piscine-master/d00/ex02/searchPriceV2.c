#include "header.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int searchPrice(struct s_art **arts, int n, char *name)
{
	int start = 0;
	int end = n;
	int mid;

	while (start <= end)
	{
		mid = (end + start) / 2;
		if (strcmp(arts[mid]->name, name) > 0)
			end = mid - 1;
		else if (strcmp(arts[mid]->name, name) < 0)
			start = mid + 1;
		else
			return (arts[mid]->price);
	}
	return -1;
}
