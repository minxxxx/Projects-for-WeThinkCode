#include "header.h"

struct s_stack	*stackInit(void)
{
	struct s_stack *stack;

	stack = (struct s_stack*)malloc(sizeof(struct s_stack));
	stack->item = NULL;
	return (stack);
}

void			push(struct s_stack *stack, char *word)
{
	struct s_item *top;

	top = (struct s_item*)malloc(sizeof(struct s_item));
	top->word = word;
	top->next = stack->item;
	stack->item = top;
}

void			*pop(struct s_stack *stack)
{
	char *word;
	struct s_item *top;

	top = stack->item;
	if (top == NULL)
		return (NULL);
	stack->item = top->next;
	word = top->word;
	free(top);
	return (word);
}

void	printReverseV2(struct s_node *lst)
{
	struct s_stack *stack;

	stack = stackInit();
	while (lst)
	{
		push(stack, lst->word);
		lst = lst->next;
	}
	while (stack->item->next)
		printf("%s ", (char*)pop(stack));
	printf("%s\n", (char*)pop(stack));
	free(stack);
}
