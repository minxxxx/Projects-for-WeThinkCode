#include "header.h"
#include <stdio.h>
#include <stdlib.h>

void sortStones(struct s_stone **stone)
{
	struct s_stone *tmp;
	struct s_hold *hold;
	struct s_hold *hold_cur;
	hold = NULL;
	tmp = *stone;

	while (tmp)
	{
		if (!hold)
		{
			hold = (struct s_hold*)malloc(sizeof(struct s_hold));
			hold_cur = hold;
		}
		hold_cur->next = NULL;
		hold_cur->num = tmp->size;
		hold_cur->begin = tmp;
		while (tmp->next && (tmp->next->size == hold_cur->num))
			tmp = tmp->next;
		hold_cur->end = tmp;
		tmp = tmp->next;
		if (tmp)
		{
			hold_cur->next = (struct s_hold*)malloc(sizeof(struct s_hold));
			hold_cur = hold_cur->next;
		}
	}


	struct s_hold *h_sort;
	struct s_hold *bub;
	struct s_hold *b_temp;
	struct s_hold *head_hold;
	struct s_hold *last;

	head_hold = hold;
	while (head_hold)
	{
		h_sort = head_hold;
		while(h_sort)

		{
			last = h_sort;
			if (last->next && (last->num > last->next->num))
			{
				bub = last->next;
				b_temp = bub->next;
				bub->next = last;
				last->next = b_temp;
			}
			h_sort = h_sort->next;
		}
		head_hold = head_hold->next;
	}
	while (hold)
	{
		printf("%d\n", hold->num);
		hold = hold->next;
	}
}
