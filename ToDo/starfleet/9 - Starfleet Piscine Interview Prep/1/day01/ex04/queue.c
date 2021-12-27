/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 16:53:20 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/02 16:53:21 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdlib.h>

struct s_queue		*queueInit(void)
{
	struct s_queue	*q;

	q = malloc(sizeof(struct s_queue));
	q->first = NULL;
	q->last = NULL;
	return (q);
}

char				*dequeue(struct s_queue *queue)
{
	struct s_node	*curr;

	curr = queue->first;
	queue->first = curr->next;
	return (curr ? curr->message : NULL);
}

void				enqueue(struct s_queue *queue, char *message)
{
	struct s_node	*new;

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
	return ;
}

char				*peek(struct s_queue *queue)
{
	return (queue->first != NULL ? queue->first->message : NULL);
}

int					isEmpty(struct s_queue *queue)
{
	return ((queue != NULL) && (queue->first != NULL) ? 0 : 1);
}
