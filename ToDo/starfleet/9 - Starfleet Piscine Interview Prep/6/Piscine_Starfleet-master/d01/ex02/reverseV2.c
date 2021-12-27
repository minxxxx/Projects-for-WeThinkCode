/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:54:35 by smonroe           #+#    #+#             */
/*   Updated: 2019/01/08 18:31:13 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static struct s_item *new(char *word)
{
	struct s_item *tmp = malloc(sizeof(*tmp));
	tmp->word = word;
	tmp->next = 0;
	return tmp;
}

struct s_stack *stackInit(void)
{
	struct s_stack *tmp = malloc(sizeof(*tmp));
	tmp->item = 0;
	return tmp;
}

void *pop(struct s_stack *stack)
{
	if (!stack)
		return 0;
	if (!stack->item)
		return 0;
	struct s_item *tmp = stack->item;
	stack->item = stack->item->next;
	void *r = tmp->word;
	free(tmp);
	return r;
}

void push(struct s_stack *stack, char *word)
{
	if (!stack)
		return ;
	if (!stack->item)
		stack->item = new(word);
	else
	{
		struct s_item *tmp = new(word);
		tmp->next = stack->item;
		stack->item = tmp;
	}
}

void	printReverseV2(struct s_node *lst)
{
	if (!lst)
		return ;
	struct s_node *tmp = lst;
	struct s_stack *stack = stackInit();
	while (tmp) {
		push(stack, tmp->word);
		tmp = tmp->next;
	}
	char *r = 0;
	printf("%s", pop(stack));
	while ((r = pop(stack)))
		printf(" %s", r);
}
