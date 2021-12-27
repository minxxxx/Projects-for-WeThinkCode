#include <string.h> //memcpy, strlen, ...
#include <stdio.h> //printf, scanf, ...
#include "header.h"

#define N 256

void countSort(unsigned char *utensils, int n)
{
	int i;
	int count[N];
	memset(count, 0, sizeof(count));
	i = 0;
	while (i < n)
	  count[utensils[i++]] += 1;
	i = 0;
	while (i < N)
	{
		memset(utensils, i, count[i]);
		utensils += count[i++];
	}
}