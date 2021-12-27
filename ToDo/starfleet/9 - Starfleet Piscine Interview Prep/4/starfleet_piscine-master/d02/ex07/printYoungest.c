#include <math.h>
#include <stdio.h>
#include "header.h"

int		get_min(int *ages, int left, int right)
{
	int mid;

	if (left == right)
		return (ages[left]);
	mid = (left + right) / 2;
	return (fmin(get_min(ages, left, mid), get_min(ages, mid + 1, right)));
}

void printYoungest(int *ages, int length)
{
	printf("Youngest : %d\n", get_min(ages, 0, length - 1));
}