/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 16:53:20 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/02 16:53:21 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>
#include <stdlib.h>

struct s_stack		*stackInit(void)
{
	struct s_stack	*ret;

	if (!(ret = (struct s_stack*)malloc(sizeof(struct s_stack))))
		return (NULL);
	ret->item = NULL;
	return (ret);
}

void				push(struct s_stack *stack, char *word)
{
	struct 			s_item *tmp;

	if (!(tmp = (struct s_item*)malloc(sizeof(struct s_item))))
		return ;
	tmp->word = word;
	tmp->next = stack->item;
	stack->item = tmp;
	return ;
}

void				*pop(struct s_stack *stack)
{
	struct s_item	*tmp;

	tmp = stack->item;
	stack->item = tmp->next;
	return (tmp);
}

void				printReverseV2(struct s_node *lst)
{
	struct s_node	*curr;
	struct s_stack	*stack;
	struct s_item	*tmp;

	curr = lst;
	stack = stackInit();
	while (curr != NULL)
	{
		push(stack, curr->word);
		curr = curr->next;
	}
	while (stack->item != NULL)
	{
		tmp = (struct s_item*)pop(stack);
		printf("%s", tmp->word);
		if (stack->item != NULL)
			putchar(' ');
	}
	putchar('\n');
	return ;
}
