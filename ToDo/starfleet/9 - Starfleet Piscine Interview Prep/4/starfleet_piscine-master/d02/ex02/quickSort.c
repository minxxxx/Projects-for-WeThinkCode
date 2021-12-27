#include <stdio.h>
#include "header.h"

int partition(struct s_player **players, int left, int right)
{
	struct s_player *player;
	int mid = players[(right + left) / 2]->score;
	while(left <= right)
	{
		while(players[left]->score > mid)
			left++;
		while(players[right]->score < mid)
			right--;
		if (left <= right)
		{
			player = players[left];
    	   	players[left] = players[right];
    	   	players[right] = player;
    	   	left++;
    	   	right--;
		}
	}
	return left;
}

void qsort(struct s_player **players, int left, int right)
{
	if(left < right)
	{
		int mid = partition(players, left, right);
		qsort(players, left, mid - 1);
		qsort(players, mid, right);
	}
}

void quickSort(struct s_player **players)
{
	int len = 0;
	while(players[len])
		len++;
	qsort(players, 0, len - 1);
}