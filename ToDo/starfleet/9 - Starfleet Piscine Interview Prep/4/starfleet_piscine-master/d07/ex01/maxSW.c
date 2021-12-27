#include <stdlib.h> //malloc, free, exit...
#include <limits.h>

#include "header.h"


struct s_deque *dequeInit(void)
{
	struct s_deque *deque;

	deque = (struct s_deque*)malloc(sizeof(struct s_deque));
	deque->first = NULL;
	deque->last = NULL;
	return deque;
}

void pushFront(struct s_deque *deque, int value)
{
	struct s_dequeNode *node = malloc(sizeof(struct s_dequeNode));
	node->value = value;
	node->prev = NULL;
	node->next = deque->first;
	if (deque->first)
		deque->first->prev = node;
	deque->first = node;
	if(!deque->last)
		deque->last = node;
}

void pushBack(struct s_deque *deque, int value)
{
	struct s_dequeNode *node = malloc(sizeof(struct s_dequeNode));
	node->value = value;
	node->prev = deque->last;
	node->next = NULL;
	if (deque->last)
		deque->last->next = node;
	deque->last = node;
	if(!deque->first)
		deque->first = node;
}

int popFront(struct s_deque *deque)
{
	struct s_dequeNode *node = deque->first;
	int value;
	if (!node)
		return INT_MIN;
	deque->first = node->next;
	if(!deque->first)
		deque->last = NULL;
	else
		deque->first->prev = NULL;
	value = node->value;
	free(node);
	return value;
}

int popBack(struct s_deque *deque)
{
	struct s_dequeNode *node = deque->last;
	int value;
	if (!node)
		return INT_MIN;
	deque->last = node->prev;
	if(!deque->last)
		deque->first = NULL;
	else
		deque->last->next = NULL;
	value = node->value;
	free(node);
	return value;
}

int empty(struct s_deque *deque)
{
	return !deque->first || !deque->last;
}

struct s_max *maxSlidingWindow(int *arr, int n, int k)
{
	struct s_max *res = malloc(sizeof(struct s_max));
	int len = n - k + 1;
	res->max = malloc(sizeof(int) * len);
	res->length = len;
	struct s_deque *deque = dequeInit();
	for (int i = 0; i < k; i++)
	{
		while(!empty(deque) && deque->last->value < arr[i])
			popBack(deque);
		pushBack(deque, arr[i]);
	}
	for (int i = k; i < n; i++)
	{
		res->max[i - k] = deque->first->value;
		while (deque->first != NULL && deque->first->value <= arr[i - k])
			popFront(deque);
		while (deque->last != NULL && deque->last->value <= arr[i])
			popBack(deque);
		pushBack(deque, arr[i]);
	}
	res->max[n - k] = popFront(deque);
	return res;
}
