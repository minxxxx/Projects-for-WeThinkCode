#include "header.h"

struct s_stack	*stackInit(void)
{
	struct s_stack *stack;

	stack = (struct s_stack*)malloc(sizeof(struct s_stack));
	stack->item = NULL;
	return (stack);
}

void			push(struct s_stack *stack, int idx)
{
	struct s_item *top;

	top = (struct s_item*)malloc(sizeof(struct s_item));
	if (top == NULL)
		return ;
	top->idx = idx;
	top->next = stack->item;
	stack->item = top;
}

int				pop(struct s_stack *stack)
{
	char idx;
	struct s_item *top;

	top = stack->item;
	if (top == NULL)
		return (0);
	stack->item = top->next;
	idx = top->idx;
	free(top);
	return (idx);
}

char			*console()
{
	char 			*msg;
	char			buffer[256];
	struct s_stack	*stack;
	int				undo_idx;

	msg = (char*)malloc(sizeof(char) * 256);
	memset(msg, 0, 256);
	stack = stackInit();
	while (1)
	{
		printf("?: ");
		scanf("%[\n]", buffer);
		scanf("%255[^\n]", buffer);
		if (strcmp(buffer, "UNDO") == 0)
		{
			undo_idx = pop(stack);
			memset(msg + undo_idx, 0, 256 - undo_idx);
		}
		else if (strcmp(buffer, "SEND") == 0)
		{
			while (stack->item)
				pop(stack);
			free (stack);
			break ;
		}
		else
		{
			push(stack, strlen(msg));
			strcat(msg, buffer);
		}
		printf("%s\n\n", msg);
	}
	return (msg);
}
