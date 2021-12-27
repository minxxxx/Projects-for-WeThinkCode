#include "header.h"
#include <stdlib.h>

struct s_queue *queueInit(void)
{
	struct s_queue *ret;

	ret = malloc(sizeof(struct s_queue));
	ret->first = NULL;
	ret->last = NULL;

	return ret;
}

char *dequeue(struct s_queue *queue)
{
	struct s_node *cur;

	cur = queue->first;
	queue->first = cur->next;
	if (cur)
		return (cur->message);
	return NULL;
}

void enqueue(struct s_queue *queue, char *message)
{
	struct s_node *new;

	new = malloc(sizeof(struct s_node));
	new->message = message;
	new->next = NULL;
	if (!queue->last)
	{
		queue->last = new;
		queue->first = new;
	}
	else
	{
		queue->last->next = new;
		queue->last = queue->last->next;
	}
}

char *peek(struct s_queue *queue)
{
	if (queue->first)
		return(queue->first->message);
	return NULL;
}

int isEmpty(struct s_queue *queue)
{
	if (queue && queue->first)
		return 0;
	return 1;
}
