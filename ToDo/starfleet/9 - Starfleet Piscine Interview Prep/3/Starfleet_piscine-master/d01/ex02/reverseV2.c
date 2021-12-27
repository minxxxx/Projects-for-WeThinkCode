#include "header.h"
#include <stdio.h>
#include <stdlib.h>

struct s_stack *stackInit(void)
{
	struct s_stack *ret;

	ret = (struct s_stack*)malloc(sizeof(struct s_stack));
	ret->item = NULL;
	return ret;
}

void push(struct s_stack *stack, char *word)
{
	struct s_item *tmp;

	tmp = (struct s_item*)malloc(sizeof(struct s_item));
	tmp->word = word;
	tmp->next = stack->item;
	stack->item = tmp;
}

void *pop(struct s_stack *stack)
{
	struct s_item *tmp;

	tmp = stack->item;
	stack->item = tmp->next;
	return (tmp);
}

void printReverseV2(struct s_node *lst)
{
	struct s_node *curr;
	struct s_stack *stack;
	struct s_item *tmp;

	stack = stackInit();
	curr = lst;
	while (curr)
	{
		push(stack, curr->word);
		curr = curr->next;
	}
	while (stack->item)
	{
		tmp = (struct s_item*)pop(stack);
		printf("%s", tmp->word);
		if (stack->item)
			printf("%s", " ");
	}
	printf("\n");
}
