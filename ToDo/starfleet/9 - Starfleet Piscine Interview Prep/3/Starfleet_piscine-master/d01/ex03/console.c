#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

struct s_stack *initStack()
{
	struct s_stack *ret;

	ret = (struct s_stack*)malloc(sizeof(struct s_stack));
	ret->item = NULL;
	return ret;
}

void push(struct s_stack *stack, int idx)
{
	struct s_item *tmp;

	tmp = (struct s_item*)malloc(sizeof(struct s_item));
	tmp->idx = idx;
	tmp->next = stack->item;
	stack->item = tmp;
}

int pop(struct s_stack *stack)
{
	struct s_item *tmp;

	tmp = stack->item;
	stack->item = tmp->next;
	return (tmp->idx);
}

char *console(void)
{
	char *input;
	struct s_stack *stack;
	char ret[250];
	int cur;


	input = malloc(251);
	stack = initStack();
	// stack = NULL;
	cur = 0;
	while (1)
	{
		bzero(input, 250);
		printf("%s", "?: ");
		// scanf("%s", input);
		fgets(input, 250, stdin);
		// printf("\n");
		input[strlen(input) - 1] = 0;
		if (strcmp(input, "UNDO") == 0)
		{
			if (stack->item)
				cur = pop(stack);
			bzero(ret + cur, 250 - cur);
		}
		else if (strcmp("SEND", input) == 0)
			break;
		else
		{
			push(stack, cur);
			memmove(ret + cur, input, strlen(input));
			cur += strlen(input);
		}
		printf("%s\n", ret);
	}
	return strdup(ret);
	// printf("%s\n", "here");
	// return NULL;
}
