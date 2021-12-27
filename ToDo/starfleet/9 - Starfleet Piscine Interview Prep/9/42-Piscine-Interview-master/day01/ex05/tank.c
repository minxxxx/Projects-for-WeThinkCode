/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:54:27 by amontano          #+#    #+#             */
/*   Updated: 2019/01/09 18:54:29 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_tank *initTank(void)
{
    struct s_tank *tank = (t_tank *)malloc(sizeof(t_tank));
     
    tank->n = 0;
    tank->stacks = (t_stack **)malloc(sizeof(t_stack *) * MAX_TANKS);
    for (int i = 0; i < MAX_TANKS; i++)
    {
        tank->stacks[i] = NULL;
    }
    (tank->stacks)[0] = stackInit();
    return (tank);
}


void tankPush(struct s_tank *tank, int energy)
{
    t_elem  *new;
    t_stack **all;
    t_stack *cur;

    all = tank->stacks;
    cur = all[tank->n];
    
    if (energy >= 10 && energy <= 100)
    {
        if (energy + cur->sum >= 1000)
        {
            tank->n += 1;
            all[tank->n] = stackInit();
            cur = all[tank->n];
        }
        if (cur)
        {
            new = new_elem(energy);
            new->next = cur->elem;
            cur->elem = new;
            cur->sum += energy;
        }
    }
}

int tankPop(struct s_tank *tank)
{
    t_stack *cur;

    cur = tank->stacks[tank->n];
    if (cur)
    {
        cur->sum -= cur->elem->energy;
        cur->elem = cur->elem->next;
        if (!cur->elem)
            tank->n -= 1;
    }
    if (tank->n > -1)
        cur = tank->stacks[tank->n];
    else
        return (0);
    return (cur->sum);
}

t_elem	*new_elem(int n)
{
	t_elem *new = (t_elem *)malloc(sizeof(t_elem));

    if (new)
    {
	    new->energy = n;
	    new->next = NULL;
    }
	return (new);
}

struct s_stack *stackInit()
{
	t_stack	*s = (t_stack *)malloc(sizeof(t_stack));
	if (s)
    {
		s->elem = NULL;
        s->sum = 0;
    }
	else
		return (NULL);
	return (s);
}