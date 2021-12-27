#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

struct s_stack *stackInit(void)
{
	struct s_stack *stack;

	stack = malloc(sizeof(struct s_stack));
	stack->elem = NULL;
	stack->sum = 0;
	return stack;
}

void tankRealloc(struct s_tank *tank, int n)
{
	struct s_stack **stacks;

	int total = tank->n + n;
	stacks = malloc(sizeof(struct s_stack *) * total);
	for (int i = 0; i < tank->n; i++)
		stacks[i] = tank->stacks[i];
	stacks[total - 1] = stackInit();
	tank->n = total;
	free(tank->stacks);
	tank->stacks = stacks;
}

void add_elem(struct s_stack *stack, int energy)
{
	struct s_elem *node;

	node = (struct s_elem *)malloc(sizeof(struct s_elem));
	node->energy = energy;
	node->next = stack->elem;
	stack->elem = node;
	stack->sum += energy;
}

int pop_elem(struct s_stack *stack)
{
	struct s_elem *node;
	int energy;

	node = stack->elem;
	if(!node)
		return 0;
	stack->elem = node->next;
	energy = node->energy;
	free(node);
	stack->sum -= energy;
	return (energy);
}

struct s_tank *initTank(void)
{
	struct s_tank *tank = malloc(sizeof(struct s_tank *));
	tank->stacks = malloc(sizeof(struct s_stack*));
	tank->stacks[0] = stackInit();
	tank->n = 1;
	return tank;
}

void tankPush(struct s_tank *tank, int energy)
{
	if (energy < 10 || energy > 100)
		return;
	if (tank->stacks[tank->n - 1]->sum + energy > 1000)
		tankRealloc(tank, 1);
	add_elem(tank->stacks[tank->n - 1], energy);
}

int tankPop(struct s_tank *tank)
{
	if(tank->n > 1 && !tank->stacks[tank->n - 1]->sum)
		tank->n--;
	int energy = pop_elem(tank->stacks[tank->n - 1]);
	return energy;
}
