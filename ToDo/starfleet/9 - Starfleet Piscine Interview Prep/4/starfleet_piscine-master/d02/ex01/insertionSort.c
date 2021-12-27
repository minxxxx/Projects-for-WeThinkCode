#include "header.h"

void insertionSort(struct s_player **players)
{
	struct s_player *player;
	int i = 1;
	while (players[i])
	{
    	int j = i;
    	while (j > 0 && players[j-1]->score < players[j]->score)
    	{
    	   	player = players[j-1];
    	   	players[j-1] = players[j];
    	   	players[j] = player;
        	j--;
    	}
    	i++;
    }
}