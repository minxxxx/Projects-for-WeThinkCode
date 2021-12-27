
#include "header.h"
#include <stdlib.h>

struct s_max *maxSlidingWindow(int *arr, int n, int k)
{
	struct s_deque	*deque;
	struct s_max	*new_arr;
	int				new_size = (n < k) ? 1 : n - k + 1;
	int				sum;

	deque = dequeInit();
	new_arr = calloc(1, sizeof(struct s_deque));
	new_arr->max = calloc(new_size, sizeof(int));
	new_arr->length = new_size;

	for (int i = 0; i < new_size; i++)
	{

	}
	
}

void pushFront(struct s_deque *deque, int value)
{
	struct s_dequeNode *new_node = calloc(1, sizeof(struct s_dequeNode));
	new_node->value = value;
	new_node->prev = NULL;
	if (!deque->first)
	{
		new_node->next = NULL;
		deque->first = new_node;
		deque->last = new_node;
	}
	else
	{
		new_node->next = deque->first;
		deque->first = new_node;
	}
}

void pushBack(struct s_deque *deque, int value)
{
	struct s_dequeNode *new_node = calloc(1, sizeof(struct s_dequeNode));
	new_node->value = value;
	new_node->next = NULL;
	if (!deque->last)
	{
		new_node->prev = NULL;
		deque->first = new_node;
		deque->last = new_node;
	}
	else
	{
		deque->last->next = new_node;
		new_node->prev = deque->last;
		deque->last = new_node;
	}
}

int popFront(struct s_deque *deque)
{
	int	tmp_value;
	struct s_dequeNode *tmp_node;

	tmp_node = deque->first;
	deque->first = deque->first->next;
	deque->first->prev = NULL;
	tmp_value = tmp_node->value;
	free(tmp_node);
	return (tmp_value);
}

int popBack(struct s_deque *deque)
{
	int	tmp_value;
	struct s_dequeNode *tmp_node;

	tmp_node = deque->last;
	deque->last = deque->last->prev;
	deque->last->next = NULL;
	tmp_value = tmp_node->value;
	free(tmp_node);
	return (tmp_value);
}

struct s_deque *dequeInit(void)
{
	struct s_max	*new;
	
	new = calloc(1, sizeof(struct s_deque));
	return (new);
}


