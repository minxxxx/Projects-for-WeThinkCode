/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:32:18 by amontano          #+#    #+#             */
/*   Updated: 2019/01/09 17:32:21 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_queue *queueInit(void)
{
	t_q *q;

	q = (t_q *)malloc(sizeof(t_q));
	q->first = NULL;
	q->last = NULL;
	return (q);
}

char *dequeue(struct s_queue *queue)
{
	t_node *f = queue->first;

	if (queue && f)
	{
		f = queue->first;
		queue->first = queue->first->next;
		if (queue->last == f->next)
			queue->last = NULL;
		return (f->message);
	}
	return (NULL);
}

void enqueue(struct s_queue *queue, char *message)
{
	t_node *new = (t_node *)malloc(sizeof(t_node));

	new->message = message;
	new->next = NULL;
	if (!queue->first)
		queue->first = new;
	if (queue->last)
		queue->last->next = new;
	queue->last = new;
}

char *peek(struct s_queue *queue)
{
	return (isEmpty(queue) ? queue->first->message : NULL);
}

int isEmpty(struct s_queue *queue)
{
	return (!queue->first && !queue->last);
}
