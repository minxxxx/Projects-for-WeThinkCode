#include "header.h"

struct s_queue 	*queueInit(void)
{
	struct s_queue *q;

	q = (struct s_queue*)malloc(sizeof(struct s_queue));
	if (q == NULL)
		return NULL;
	q->first = NULL;
	q->last = NULL;
	return (q);
}

void			enqueue(struct s_queue *q, char *msg)
{
	struct s_node *node;

	node = (struct s_node*)malloc(sizeof(struct s_node));
	if (node == NULL)
		return ;
	node->message = msg;
	node->next = NULL;
	if (q->first == NULL)
		q->first = node;
	else
		q->last->next = node;
	q->last = node;
}

char 			*dequeue(struct s_queue *q)
{
	struct s_node	*first;
	char			*msg;

	first = q->first;
	if (first == NULL)
		return (NULL);
	q->first = first->next;
	if (q->first == NULL)
		q->last = NULL;
	msg = first->message;
	free(first);
	return (msg);
}

char			*peek(struct s_queue *q)
{	
	return (q->first == NULL ? NULL : q->first->message);
}

int				isEmpty(struct s_queue *q)
{
	return (q->first == NULL);
}
