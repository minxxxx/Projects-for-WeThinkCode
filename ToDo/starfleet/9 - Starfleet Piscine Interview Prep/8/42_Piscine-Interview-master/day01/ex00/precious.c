/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 16:53:20 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/02 16:53:21 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdlib.h>
#include <strings.h>

static void			initList(struct s_node *head)
{
	struct s_node	*curr;
	struct s_node	*prev;
	curr = head;
	prev = NULL;
	curr->next = NULL;

	for (int i = 0; CS[i] != '\0'; i += 1)
	{
		curr->c = CS[i];
		if (prev != NULL)
			curr->prev = prev;
		prev = curr;
		if (CS[i + 1] == '\0')
			break;
		curr->next = (struct s_node*)malloc(sizeof(struct s_node));
		curr = curr->next;
	}
	curr->next = head;
	head->prev = curr;
	return;
}

static char			*getMessage(struct s_node *head, int *text, int size)
{
	char			*msg;

	if (!(msg = (char*)malloc(size + 1)))
		return (NULL);
	bzero(msg, size + 1);
	for (int i = 0; i < size; i += 1)
	{
		while (text[i] != 0)
		{
			if (text[i] > 0)
			{
				text[i] -= 1;
				head = head->next;
			}
			else
			{
				text[i] += 1;
				head = head->prev;
			}
		}
		msg[i] = head->c;
	}
	return (msg);
}

char				*precious(int *text, int size)
{
	struct s_node	*head;

	if (!(head = (struct s_node*)malloc(sizeof(struct s_node))))
		return (NULL);
	initList(head);
	return (getMessage(head, text, size));
}
