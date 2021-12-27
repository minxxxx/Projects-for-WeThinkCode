#include "header.h"

struct s_dequeNode *newNode(int value)
{
	struct s_dequeNode *new;

	new = (struct s_dequeNode*)malloc(sizeof(struct s_dequeNode));
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

struct s_deque *dequeInit(void)
{
	struct s_deque *deque;

	deque = (struct s_deque*)malloc(sizeof(struct s_deque));
	deque->first = NULL;
	deque->last = NULL;
	return (deque);
}

void pushFront(struct s_deque *deque, int value)
{
	struct s_dequeNode *new;

	new = newNode(value);
	if (deque->first)
		deque->first->prev = new;
	new->next = deque->first;
	deque->first = new;
	if (new->next == NULL)
		deque->last = new;
}

void pushBack(struct s_deque *deque, int value)
{
	struct s_dequeNode *new;

	new = newNode(value);
	if (deque->last)
		deque->last->next = new;
	new->prev = deque->last;
	deque->last = new;
	if (new->prev == NULL)
		deque->first = new;
}

int popFront(struct s_deque *deque)
{
	struct s_dequeNode	*pop_node;
	int					pop_val;

	if (deque->first)
	{
		pop_node = deque->first;
		pop_val = pop_node->value;
		free(pop_node);
		deque->first = deque->first->next;
		if (deque->first)
			deque->first->prev = NULL;
		else
			deque->last = NULL;
	}
	else
		pop_val = INT_MIN;
	return (pop_val);
}

int popBack(struct s_deque *deque)
{
	struct s_dequeNode	*pop_node;
	int					pop_val;

	if (deque->last)
	{
		pop_node = deque->last;
		pop_val = pop_node->value;
		free(pop_node);
		deque->last = deque->last->prev;
		if (deque->last)
			deque->last->next = NULL;
		else
			deque->first = NULL;
	}
	else
		pop_val = INT_MIN;
	return (pop_val);
}

struct s_max *maxSW(int *arr, int n, int k)
{
	struct s_max	*maxs;
	struct s_deque	*deque;
	int				i;

	maxs = (struct s_max*)malloc(sizeof(struct s_max));
	maxs->length = n - k + 1;
	maxs->max = (int*)malloc(sizeof(int) * maxs->length);

	deque = dequeInit();

	for (i = 0; i < k; i++)
	{
		while (deque->last != NULL && arr[deque->last->value] <= arr[i])
			popBack(deque);
		pushBack(deque, i);
	}

	for (; i < n; i++)
	{
		maxs->max[i - k] = arr[deque->first->value];
		while (deque->first != NULL && deque->first->value <= i - k)
			popFront(deque);
		while (deque->last != NULL && arr[deque->last->value] <= arr[i])
			popBack(deque);
		pushBack(deque, i);
	}
	maxs->max[i - k] = arr[deque->first->value];
	
	return(maxs);
}
