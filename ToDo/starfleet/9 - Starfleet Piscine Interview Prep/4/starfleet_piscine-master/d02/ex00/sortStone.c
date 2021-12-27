#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

void sortStones(struct s_stone **stone)
{
	int swap;

	struct s_stone *p1;
	struct s_stone *p2 = NULL;

	if (!stone)
		return;
	swap = 1;
	while(swap)
	{	
		swap = 0;
		p1 = *stone;
		while(p1->next != p2)
		{
			if(p1->size > p1->next->size)
			{
				swap = p1->size;
				p1->size = p1->next->size;
				p1->next->size = swap;
				swap = 1;
			}
			p1 = p1->next;
		}
		p2 = p1;
	}
}