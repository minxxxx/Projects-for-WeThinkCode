#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <stdlib.h> //malloc, free, exit...
#include "header.h"

struct s_stack *stackInit(void)
{
	struct s_stack *stack = malloc(sizeof(struct s_stack));
	stack->item = NULL;
	return stack;
}

void *pop(struct s_stack *stack)
{
	struct s_item *item = stack->item;
	if(item)
		stack->item = item->next;
	return item;
}

void push(struct s_stack *stack, char *word)
{
	struct s_item *item = malloc(sizeof(struct s_item));
	item->word = strdup(word);
	item->next = stack->item;
	stack->item = item;
}

void printReverseV2(struct s_node *lst)
{
	struct s_item *item;
	struct s_stack *stack = stackInit();
	while(lst)
	{
		push(stack, lst->word);
		lst = lst->next;
	}
	while((item = pop(stack)))
	{
		printf("%s", item->word);
		if (item->next)
			printf(" ");
	}
}
