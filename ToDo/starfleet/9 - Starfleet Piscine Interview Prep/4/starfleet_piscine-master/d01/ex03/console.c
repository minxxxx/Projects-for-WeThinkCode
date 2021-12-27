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

int pop(struct s_stack *stack)
{
	struct s_item *item = stack->item;
	if(item)
	{
		stack->item = item->next;
		return item->idx;
	}
	return 0;
}

void push(struct s_stack *stack, int idx)
{
	struct s_item *item = malloc(sizeof(struct s_item));
	item->idx = idx;
	item->next = stack->item;
	stack->item = item;
}

char *console(void)
{
	size_t BUFF_SIZE = 255;
	char *message = calloc(sizeof(char), BUFF_SIZE + 1);
	size_t n;
	char *input = NULL;
	struct s_stack *stack = stackInit();
	printf("?: ");
	while((n = getline(&input, &BUFF_SIZE, stdin)) > 0)
	{
		//printf("READ %zu characters: %s \n", n, input);
		if (!strcmp(input, "SEND\n"))
			return message;
		else if (!strcmp(input, "UNDO\n"))
		{
			message[pop(stack)] = 0;
			printf("%s\n", message);
		}
		else if (n > 1)
		{
			push(stack, strlen(message));
			if(message[0])
				strcat(message, " ");
			strncat(message, input, n - 1);
			printf("%s\n", message);
		}
		printf("\n");
		printf("?: ");
	}
	return message;
}
