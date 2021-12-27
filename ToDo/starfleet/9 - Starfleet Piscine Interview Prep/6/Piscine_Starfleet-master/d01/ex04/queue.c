/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 04:44:44 by smonroe           #+#    #+#             */
/*   Updated: 2019/01/09 18:01:20 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_queue *queueInit(void)
{
	struct s_queue *tmp = malloc(sizeof(*tmp));
	tmp->first = tmp->last = 0;
	return tmp;
}

void enqueue(struct s_queue *queue, char *message)
{
	struct s_node *new = (struct s_node *)malloc(sizeof(struct s_node));
	new->message = message;
	new->next = NULL;
	if (queue->last)
		queue->last->next = new;
	queue->last = new;
	if (queue->first == NULL)
		queue->first = new;
}

char *dequeue(struct s_queue *queue)
{
	struct s_node *ret = queue->first;
	if (!queue->first && !queue->last)
		return NULL;
	if (queue->first == queue->last)
		queue->first = queue->last = NULL;
	if (queue->first)
		queue->first = queue->first->next;
	return ret->message;
}

char	*peek(struct s_queue *queue)
{
	if (queue->first)
		return queue->first->message;
	return NULL;
}

int isEmpty(struct s_queue *queue)
{
	if ((queue == NULL) || (queue->first == NULL && queue->last == NULL))
	{
		return 1;
	}
	return 0;
}
