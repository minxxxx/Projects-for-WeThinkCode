/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iiliuk <iiliuk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:19:46 by iiliuk            #+#    #+#             */
/*   Updated: 2017/03/22 16:52:56 by iiliuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	find_min_index(int *stack, int len)
{
	register int i;
	register int tmp;
	register int index;

	if (len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < len)
	{
		if (tmp > stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int 	find_max_index(int *stack, int len)
{
	register int i;
	register int tmp;
	register int index;

	if (len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < len)
	{
		if (tmp < stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int 	find_min_elem(int *stack, int stack_len)
{
	register int i;
	register int tmp;
	register int index;

	if (stack_len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < stack_len) 
	{
		if (tmp > stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int 	find_max_elem(int *stack, int stack_len)
{
	int i;
	int tmp;
	int index;

	if (stack_len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < stack_len) 
	{
		if (tmp < stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	place_smallest_first_a(t_stack *stack)
{
	register int min_index;

	min_index = find_min_index(stack->stack_a, stack->a_size);
	if (min_index <= stack->a_size / 2)
		while (min_index--)
			apply_ra(stack);
	else
		while ((stack->a_size - min_index) > 0)
		{
			apply_rra(stack);
			min_index++;
		}
}
