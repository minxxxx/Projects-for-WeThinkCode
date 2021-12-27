#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

struct s_queue *queueInit(void)
{
	struct s_queue *queue = malloc(sizeof(struct s_queue));
	if(!queue)
		return NULL;
	queue->first = NULL;
	queue->last = NULL;
	return queue;
}

char *dequeue(struct s_queue *queue)
{
	char *message;
	struct s_node *node = queue->first;
	if(!node)
		return NULL;
	else
	{
		queue->first = node->next;
		if(!(queue->first))
			queue->last = NULL;
		message = strdup(node->message);
		free(node);
		return message;
	}
	return NULL;
}

void enqueue(struct s_queue *queue, char *message)
{
	struct s_node *node = malloc(sizeof(struct s_node));
	node->message = strdup(message);
	node->next = NULL;
	if(!isEmpty(queue))
		queue->last->next = node;
	else
		queue->first = node;
	queue->last = node;
}

char *peek(struct s_queue *queue)
{
	if(isEmpty(queue))
		return NULL;
	else
		return(queue->first->message);
}

int isEmpty(struct s_queue *queue)
{
	return(queue->last == NULL || queue->first == NULL);
}
