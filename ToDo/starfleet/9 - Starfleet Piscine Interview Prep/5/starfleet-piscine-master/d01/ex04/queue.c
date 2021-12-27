/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 21:08:49 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/24 21:46:59 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>

struct s_queue *queueInit(void)
{
	struct s_queue *new_queue;
	new_queue = calloc(1, sizeof(struct s_queue));
	new_queue->first = NULL;
	new_queue->last = NULL;
	return (new_queue);
}

char *dequeue(struct s_queue *queue)
{
	char	*ret;

	if (!queue->first)
		return (NULL);
	struct s_node *tmp = queue->first;
	queue->first = queue->first->next;
	ret = strdup(tmp->message);
	free(tmp);
	return (ret);
}

void enqueue(struct s_queue *queue, char *message)
{
	struct s_node	*new_node;
	new_node = calloc(1, sizeof(struct s_node));
	new_node->message = message;
	new_node->next = NULL;
	if (!queue->last)
	{
		queue->first = new_node;
		queue->last = new_node;
		return ;
	}
	queue->last->next = new_node;
	queue->last = new_node;
}

char *peek(struct s_queue *queue)
{
	if (!queue->first)
		return (NULL);
	return (queue->first->message);
}

int isEmpty(struct s_queue *queue)
{
	return ((!queue->first) ? 1 : 0);
}
