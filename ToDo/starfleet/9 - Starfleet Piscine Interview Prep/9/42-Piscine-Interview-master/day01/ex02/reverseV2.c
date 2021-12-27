/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 03:22:21 by amontano          #+#    #+#             */
/*   Updated: 2019/01/09 03:22:25 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


struct s_stack *stackInit(void)
{
	t_stack	*s = (t_stack *)malloc(sizeof(t_stack));
	if (s)
		s->item = NULL;
	else
		return (NULL);
	return (s);
}

void *pop(struct s_stack *stack)
{
	t_item	*cursor = NULL;
	t_item	*next 	= NULL;

	cursor = stack->item;
	if (cursor && cursor->next)
		next = cursor->next;
	if (cursor)
	{
		free(cursor);
		cursor = next;
	}
	return (cursor);
}

t_item	*new_item(char *word)
{
	t_item *new = malloc(sizeof(t_item));
	new->word = word;
	new->next = NULL;
	return (new);
}

void push(struct s_stack *stack, char *word)
{
	t_item	*push = new_item(word);
	push->next = stack->item;
	stack->item = push;
}

void printReverseV2(struct s_node *lst)
{
	t_stack	*stack = stackInit();
	while (lst)
	{
		if (lst->word)
			push(stack, lst->word);
		lst = lst->next;
	}
	printf("%s", stack->item->word);
	stack->item = (t_item *)pop(stack);
	while (stack->item)
	{
		printf(" %s", stack->item->word);
		stack->item = (t_item *)pop(stack);
	}
	free(stack);
	printf("\n");
}