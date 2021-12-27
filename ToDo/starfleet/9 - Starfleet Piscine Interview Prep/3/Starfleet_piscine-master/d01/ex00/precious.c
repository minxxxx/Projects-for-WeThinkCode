#include <stdlib.h>
#include <strings.h>
#include "header.h"
#include <stdio.h>

char *precious(int *text, int size)
{
	int i = 0;
	struct s_node *head;
	struct s_node *curr;
	struct s_node *prev;
	char *ret;

	prev = NULL;
	ret = (char*)malloc(size + 1);
	bzero(ret, size + 1);
	head = (struct s_node*)malloc(sizeof(struct s_node));
	curr = head;
	curr->next = NULL;
	while (CS[i])
	{
		curr->c = CS[i];
		i++;
		if (prev)
			curr->prev = prev;
		prev = curr;
		if (CS[i])
		{
			curr->next = (struct s_node*)malloc(sizeof(struct s_node));
			curr = curr->next;
		}
		else
		{
			curr->next = head;
			head->prev = curr;
		}
	}
	i = 0;
	while (i < size)
	{
		while (text[i] != 0)
		{
			if (text[i] > 0)
			{
				text[i]--;
				head = head->next;
			}
			else if (text[i] < 0)
			{
				text[i]++;
				head = head->prev;
			}
		}
		ret[i] = head->c;
		i++;
	}

	return ret;
}
