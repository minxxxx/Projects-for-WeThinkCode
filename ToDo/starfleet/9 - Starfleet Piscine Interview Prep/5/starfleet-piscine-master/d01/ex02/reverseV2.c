/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:14:07 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/24 15:44:44 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct s_stack	*stackInit(void)
{
	struct s_stack *new_stack;
	
	new_stack = calloc(1, sizeof(struct s_stack));
	new_stack->item = NULL;
	return (new_stack);
}

void			*pop(struct s_stack *stack)
{
	struct s_item *top;
	top = stack->item;
	stack->item = stack->item->next;
	return (top);
}

void			push(struct s_stack *stack, char *word)
{
	struct s_item *new_item;

	new_item = calloc(1, sizeof(struct s_item));
	new_item->word = word;
	new_item->next = stack->item;
	stack->item = new_item;
}

void printReverseV2(struct s_node *lst)
{
	struct s_stack	*stack;
	struct s_item	*popped_item;

	stack = stackInit();
	while (lst)
	{
		push(stack, lst->word);
		lst = lst->next;
	}
	while (stack->item)
	{
		popped_item = (struct s_item *)pop(stack);
		write(1, popped_item->word, strlen(popped_item->word));
		if (!stack->item)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
	}
}