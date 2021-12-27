/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:09:37 by smonroe           #+#    #+#             */
/*   Updated: 2019/01/09 20:42:21 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_tank *initTank(void)
{
	struct s_tank *tmp = malloc(sizeof(*tmp));
	if (!tmp)
		return 0;
	tmp->stacks = malloc(sizeof(*(tmp->stacks)) * NUM_STACK);
	if (!tmp->stacks)
		return 0;
	for (int i = 0; i < NUM_STACK; i++)
		tmp->stacks[i] = 0;
	tmp->stacks[0] = stackInit();
	if (!tmp->stacks[0])
		return 0;
	tmp->n = 0;
	return tmp;
}

void tankPush(struct s_tank *tank, int energy)
{
	if (!tank) return ;
	if (tank->stacks[tank->n]->sum + energy >= CAPACITY) {
		if (tank->n < NUM_STACK) {
			tank->stacks[++(tank->n)] = stackInit();
		}
		else {
			printf("Max Capacity Tank!!!\n");
			exit(1);
		}
	}
	if(!tank->stacks[tank->n])
		return ;
	push(tank->stacks[tank->n], energy);
}

int tankPop(struct s_tank *tank)
{
	if (!tank || !tank->stacks || tank->n < 0) return 0;
	if (tank->stacks[tank->n]->elem)
		if (tank->stacks[tank->n]->sum - tank->stacks[tank->n]->elem->energy <= 0)
			return (pop(tank->stacks[tank->n--]));
	return (pop(tank->stacks[tank->n]));
}

/*
** Stack operations
*/

struct s_elem	*new_elem(int energy)
{
	struct s_elem *tmp = malloc(sizeof(*tmp));
	if (!tmp) return 0;
	tmp->energy = energy;
	tmp->next = 0;
	return tmp;
}

struct s_stack			*stackInit(void)
{
	struct s_stack *tmp = malloc(sizeof(*tmp));
	if (!tmp) return 0;
	tmp->elem = 0;
	tmp->sum = 0;
	return tmp;
}

int		pop(struct s_stack *stack)
{
	if (!stack || !stack->elem)
		return 0;
	struct s_elem *tmp = stack->elem;
	stack->elem = stack->elem->next;
	int r = tmp->energy;
	free(tmp);
	stack->sum -= r;
	return r;
}

void	push(struct s_stack *stack, int energy)
{
	if (!stack)
		return ;
	if (!stack->elem)
	{
		stack->elem = new_elem(energy);
		stack->sum += energy;
	}
	else
	{
		struct s_elem *tmp = new_elem(energy);
		tmp->next = stack->elem;
		stack->elem = tmp;
		stack->sum += energy;
	}
}
