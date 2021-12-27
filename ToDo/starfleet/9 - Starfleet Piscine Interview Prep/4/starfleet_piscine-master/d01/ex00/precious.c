#include <stdlib.h> //malloc, free, exit...
#include "header.h"

struct s_node *lstnew(char c)
{
	struct s_node *node;

	node = (struct s_node*)malloc(sizeof(struct s_node));
	node->c = c;
	node->next = node;
	node->prev = node;
	return node;
}

void lstadd(struct s_node **list, struct s_node *new)
{
	struct s_node *first = *list;
	if (!first)
		*list = new;
	else
	{
		new->prev = first->prev;
		new->next = first;
		new->prev->next = new;
		new->next->prev = new;
	}
}

char *precious(int *text, int size)
{
	char *str = calloc(sizeof(char), size + 1);
	struct s_node *list = NULL;
	char *s = CS;
	while(*s)
		lstadd(&list, lstnew(*(s++)));
	for (int i = 0; i < size; ++i)
	{
		if(text[i] < 0)
		{
			for (int j = 0; j > text[i]; j--)
			{
				list = list->prev;
			}
		}
		else if(text[i] > 0)
		{
			for (int j = 0; j < text[i]; j++)
			{
				list = list->next;
			}
		}
		str[i] = list->c;
	}
	return str;
}