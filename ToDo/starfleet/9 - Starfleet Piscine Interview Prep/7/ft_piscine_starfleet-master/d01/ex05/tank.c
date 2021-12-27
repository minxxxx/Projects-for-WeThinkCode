#include "header.h"



void			stackPush(struct s_stack *stack, int energy)
{
	struct s_elem *new_top;

	new_top = (struct s_elem*)malloc(sizeof(struct s_elem));
	new_top->energy = energy;
	new_top->next = stack->elem;
	stack->elem = new_top;
	stack->sum += energy;
}

int				stackPop(struct s_stack *stack)
{
	int				energy;
	struct s_elem	*top;

	top = stack->elem;
	if (top == NULL)
		return (0);
	stack->elem = top->next;
	energy = top->energy;
	stack->sum -= energy;
	free(top);
	return (energy);
}

struct s_tank	*initTank(void)
{
	struct s_tank *t;

	t = (struct s_tank*)malloc(sizeof(struct s_tank));
	if (t == NULL)
		return (NULL);
	t->stacks = NULL;
	t->n = 0;
	return (t);
}

void			add_stack(struct s_tank *t)
{
	struct s_stack *new_stack;
	
	(t->n)++;
	t->stacks = (struct s_stack**)realloc(t->stacks, sizeof(struct s_stack*) * (t->n));
	new_stack = (struct s_stack*)malloc(sizeof(struct s_stack));
	new_stack->elem = NULL;
	new_stack->sum = 0;
	t->stacks[t->n - 1] = new_stack;
}

void			rm_stack(struct s_tank *t)
{
	free(t->stacks[t->n - 1]);
	(t->n)--;
	if (t->n == 0)
	{
		free(t->stacks);
		t->stacks = NULL;
	}
	t->stacks = (struct s_stack**)realloc(t->stacks, sizeof(struct s_stack*) * (t->n));
}	

void			tankPush(struct s_tank *t, int energy)
{
	if (t->stacks == NULL || t->stacks[t->n - 1]->sum + energy > 1000)
		add_stack(t);	
	stackPush(t->stacks[t->n - 1], energy);
}

int				tankPop(struct s_tank *t)
{
	int energy;
	
	if (t->n == 0)
		return (0);
	energy = stackPop(t->stacks[t->n - 1]);
	if (t->stacks[t->n - 1]->sum == 0)
		rm_stack(t);
	return (energy);
}
