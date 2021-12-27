#include <string.h> //memcpy, strlen, ...
#include <stdio.h> //printf, scanf, ...

#include "header.h"

void swap(struct s_art **arr, int a, int b)
{
	struct s_art *temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void heapify(struct s_art **arr, int i, int n)
{
	int max = i;
	if (2 * i + 1 < n && strcmp(arr[2 * i + 1]->name, arr[i]->name) > 0)
		max = 2 * i + 1;
	if (2 * i + 2 < n && strcmp(arr[2 * i + 2]->name, arr[max]->name) > 0)
		max = 2 * i + 2;
	if (max != i)
	{
		swap(arr, i, max);
		heapify(arr, max, n);
	}
}

void buildHeap(struct s_art **arr, int n)
{
	for (int i = n / 2; i >= 0; i--)
		heapify(arr, i, n);
}

void heapSort(struct s_art **masterpiece, int n)
{
	buildHeap(masterpiece, n);
	for(int i = n - 1; i >= 0; i--)
	{
		swap(masterpiece, i , 0);
		heapify(masterpiece, 0, i);
	}
}