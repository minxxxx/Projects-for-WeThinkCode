#include "header.h"
#include <stdlib.h> //malloc, free, exit...
#include <stdio.h> //printf, scanf, ...

struct s_player **merge(struct s_player **left, struct s_player **right, int len)
{
	struct s_player **arr = calloc(sizeof(struct s_player *), len + 1);
	struct s_player **curr = arr;
	while(*left || *right)
	{
		if(!*left)
			*(curr++) = *(right++);
		else if(!*right)
			*(curr++) = *(left++);
		else if((*left)->score >= (*right)->score)
			*(curr++) = *(left++);
		else
			*(curr++) = *(right++);
	}
	return arr;
}

struct s_player **mSort(struct s_player **players, int left, int right)
{
	struct s_player **arr;
	struct s_player **left_half;
	struct s_player **right_half;
	int mid = (left + right) / 2;
	if(right == left)
	{
		arr = calloc(sizeof(struct s_player *), 2);
		*arr = players[left];
		return arr;
	}
	left_half = mSort(players, left, mid);
	right_half = mSort(players, mid + 1, right);
	arr = merge(left_half, right_half, right - left + 1);
	free(left_half);
	free(right_half);
	return arr;
}

struct s_player **mergeSort(struct s_player **players)
{
	int len = 0;
	if(!players)
		return NULL;
	while(players[len])
		len++;
	return mSort(players, 0, len - 1);
}