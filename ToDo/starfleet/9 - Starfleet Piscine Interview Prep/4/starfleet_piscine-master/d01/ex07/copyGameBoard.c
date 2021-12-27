#include <stdlib.h> //malloc, free, exit...
#include "header.h"

int find_node(struct s_node *begin, struct s_node *goal)
{
	int i = 0;
	while (begin != goal)
	{
		begin = begin->next;
		i++;
	}
	return i;
}

struct s_node *get_node(struct s_node *begin, int n)
{
	int i = 0;
	while(i < n)
	{
		begin = begin->next;
		i++;
	}
	return begin;
}

struct s_node *clone_nodes(struct s_node *node)
{
	struct s_node *new_list;
	struct s_node *current;

	new_list = malloc(sizeof(struct s_node));
	new_list->value = node->value;
	new_list->random = NULL;
	current = new_list;
	while (node->next)
	{
		current->next = malloc(sizeof(struct s_node));
		current = current->next;
		node = node->next;
		current->value = node->value;
		current->random = NULL;
	}
	current ->next = NULL;
	return new_list;
}

void fill_others(struct s_node *new, struct s_node *old)
{
	int n;
	struct s_node *node1;
	struct s_node *node2;
	node1 = old;
	node2 = new;
	while(node1)
	{
		if(node1->random == NULL)
			node2->random = NULL;
		else if (node1->random == node1)
			node2->random = node2;
		else
		{
			n = find_node(old, node1->random);
			node2->random = get_node(new, n);
		}
		node1 = node1->next;
		node2= node2->next;
	}
}

struct s_node *cloneGameBoard(struct s_node *node)
{
	if (!node)
		return NULL;
	struct s_node *new_list;

	new_list = clone_nodes(node);
	fill_others(new_list, node);
	return new_list;
}