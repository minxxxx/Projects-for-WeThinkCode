#include <stdio.h> //printf, scanf, ...
#include "header.h"

int bsearch(int *arr, int offset, int n, int value)
{
	if (n > 0)
	{
		int mid = n / 2;
		if(arr[offset + mid] == value)
			return offset + mid;
		else if(value < arr[offset + mid])
			return bsearch(arr, offset, mid, value);
		else
			return bsearch(arr, offset + mid, mid, value);
	}
	return -1;
}

int	searchShifted(int *rocks, int length, int value)
{
	int i = 0;
	if(!rocks)
		return -1;
	while (i < length - 1 && rocks[i] <= rocks[i+1])
	{
		if(rocks[i] == value)
			return i;
		i++;
	}
	return bsearch(rocks, i, length - i, value);
}