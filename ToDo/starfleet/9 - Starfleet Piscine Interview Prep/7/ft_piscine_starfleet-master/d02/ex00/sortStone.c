#include "header.h"
#include <stdio.h>
struct s_stone	*skip(struct s_stone *list_iter)
{	
	struct s_stone *new;

	new = list_iter->next;
	while (new && new->next && new->next->size == new->size)
		new = new->next;
	return (new);
}

void			swap(struct s_stone **l1, struct s_stone **l2, struct s_stone *prev)
{
	struct s_stone *tmp;

	tmp = prev->next;
	prev->next = (*l1)->next;
	(*l1)->next = (*l2)->next;
	(*l2)->next = tmp;
	
	tmp = *l1;
	*l1 = *l2;
	*l2 = tmp;
}


int				list_len(struct s_stone	*head)
{
	struct s_stone	*list_iter;
	int				n;

	list_iter = head;
	n = 0;
	while (list_iter)
	{
		if (list_iter->next == NULL || list_iter->next->size != list_iter->size)
			n++;
		list_iter = list_iter->next;
	}
	return (n);
}


void			sortStones(struct s_stone **head)
{ 
	struct s_stone	*dummy_head;
	struct s_stone	*prev;
	struct s_stone	*l1;
	struct s_stone	*l2;
	int 			n;

	dummy_head = (struct s_stone*)malloc(sizeof(struct s_stone));
	dummy_head->next = *head;
	n = list_len(*head);
	for (int i = 0; i < n - 1; i++)
	{
		prev = dummy_head;
		l1 = skip(dummy_head);
		l2 = skip(skip(dummy_head));
		for (int j = 0; j < n - i - 1; j++)
		{
			if (l1->size > l2->size)
				swap(&l1, &l2, prev);
			prev = skip(prev);
			l1 = skip(l1);
			l2 = skip(l2);
		}
	}                        

	*head = dummy_head->next;
	free(dummy_head);
}
