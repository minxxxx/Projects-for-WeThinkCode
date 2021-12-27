#include "header.h"

struct s_stack *initStack(void)
{
	struct s_stack *stack;

	stack = (struct s_stack*)malloc(sizeof(struct s_stack));
	stack->top = NULL;
	return (stack);
}

void			push(struct s_stack *stack, struct s_node *node)
{
	struct s_item *item;

	item = (struct s_item*)malloc(sizeof(struct s_item));
	item->node = node;
	item->next = stack->top;
	stack->top = item;
}

struct s_node	*pop(struct s_stack *stack)
{
	struct s_item	*item;
	struct s_node	*node;

	item = stack->top;
	stack->top = stack->top->next;
	node = item->node;
	free(item);
	return (node);
}

void			createPath(struct s_node *root, struct s_stack *stack, char *species)
{
	int i;

	if (root == NULL)
		return ;
	if (strcmp(root->name, species) == 0)
	{
		push(stack, root);
		return ;
	}
	i = 0;
	while (root->children[i])
	{
		createPath(root->children[i], stack, species);
		if (stack->top)
		{
			push(stack, root);
			break ;
		}
		i++;
	}
}

struct s_node 	*getLCA(struct s_stack *stack1, struct s_stack *stack2)
{
	struct s_node *LCA;

	LCA = NULL;
	while (stack1->top != NULL && stack2->top != NULL &&
		   strcmp(stack1->top->node->name, stack2->top->node->name) == 0)
	{
		LCA = pop(stack1);
		pop(stack2);
	}
	return (LCA);
}

struct s_node	*findParent(struct s_node *root, char *species1, char *species2)
{
	struct s_stack	*stack1;
	struct s_stack	*stack2;
	struct s_node	*LCA;

	stack1 = initStack();
	stack2 = initStack();
	createPath(root, stack1, species1);
	createPath(root, stack2, species2);

	//printf("Path for %s:\n\n", species1);
	//while (stack1->top)
	//	printf("%s\n", pop(stack1)->name);
	//printf("\nPath for %s:\n\n", species2);
	//while (stack2->top)
	//printf("%s\n", pop(stack2)->name);
	LCA = getLCA(stack1, stack2);

	while (stack1->top && stack2->top)
	{
		pop(stack1);
		pop(stack2);
	}
	free(stack1);
	free(stack2);

	return (LCA);
}
