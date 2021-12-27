#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int isEmpty(struct s_queue *queue)
{
	return(queue->last == NULL || queue->first == NULL);
}

struct s_queue *queueInit(void)
{
	struct s_queue *queue = malloc(sizeof(struct s_queue));
	if(!queue)
		return NULL;
	queue->first = NULL;
	queue->last = NULL;
	return queue;
}

struct s_node *dequeue(struct s_queue *queue)
{
	struct s_item *item = queue->first;
	struct s_node *node;
	if(!item)
		return NULL;
	else
	{
		queue->first = item->next;
		node = item -> node;
		if(!(queue->first))
			queue->last = NULL;
		free(item);
		return node;
	}
	return NULL;
}

void enqueue(struct s_queue *queue, struct s_node *node, int level)
{
	struct s_item *item = malloc(sizeof(struct s_item));
	item->node = node;
	item->next = NULL;
	item->level = level;
	if(!isEmpty(queue))
		queue->last->next = item;
	else
		queue->first = item;
	queue->last = item;
}

int peek_level(struct s_queue *queue)
{
	if(isEmpty(queue))
		return 0;
	else
		return(queue->first->level);
}

int find(struct s_queue *queue, struct s_node *node)
{
	struct s_item *item = queue ->first;
	while(item)
	{
		if(item->node == node)
			return 1;
		item = item->next;
	}
	return 0;
}

int	minimumMoves(struct s_node *begin)
{
	struct s_node *node = begin;
	struct s_queue *queue = queueInit();
	struct s_queue *visited = queueInit();
	int level;
	enqueue(queue, node, 0);
	while(!isEmpty(queue))
	{
		level = peek_level(queue);
		node = dequeue(queue);
		enqueue(visited, node, 0);
		if(node->next && !find(visited, node->next))
			enqueue(queue, node->next, level + 1);
		if(node->random && !find(visited, node->random))
			enqueue(queue, node->random, level + 1);
		if(node->isFinal)
		{
			free(queue);
			free(visited);
			return level;
		}
	}
	return 0;
}