/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:30:44 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/14 14:30:46 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void astar(t_env *env)
{
	t_tree_state state_tree; // added for better processing speed
	t_state_list *opened = NULL;
	t_state *best_state;
	t_state_list *expend;
	t_state_list *tmp;
	t_state *tmp_state; // changed for better processing speed
	int	in_closed;
	int	complexity_time = 0;
	int	complexity_size = 0;
	int	success = 0;
	int	size_tmp;
	int opened_size = 0;
	int closed_size = 0;
	int tmp_g;
	int is_closed = 0;

	memset(&state_tree, 0, sizeof(state_tree));
	if (!(state_tree.child = malloc(sizeof(*state_tree.child) * env->size * env->size)))
	{
		ft_putendl_fd("nuzzle: malloc failed", 2);
		exit(EXIT_FAILURE);
	}
	memset(state_tree.child, 0, sizeof(*state_tree.child) * env->size * env->size);
	push_list_state(&opened, env->start);
	push_tree_state(env, &state_tree, env->start, 1); // added for better processing speed
	if ((size_tmp = opened_size + closed_size) > complexity_size)
	{
		complexity_size = size_tmp;
	}
	while (opened)
	{
		best_state = opened->state;
		complexity_time++;
		if (best_state->h == 0)
		{
			success = 1;
			break;
		}
		tmp = opened; // added for better processing speed
		opened = opened->next; // added for better processing speed
		free(tmp); // added for better processing speed
		opened_size--; // decrement the number of open blocks
		closed_size++; // increment the number of closed blocks
		set_tree_state(env, &state_tree, best_state, 0);
		expend = expend_state(env, best_state);
		if ((size_tmp = opened_size + closed_size + size_list_state(expend)) > complexity_size)
		{
			complexity_size = size_tmp;
		}
		while (expend)
		{
			tmp_state = get_tree_state(env, &state_tree, expend->state, &is_closed);
			in_closed = tmp_state != NULL && is_closed;
			if (in_closed)
			{
				tmp = expend;
				expend = expend->next;
				free_state(env, tmp->state);
				free(tmp);
				continue;
			}
			tmp_g = best_state->g + 1;
			if (!tmp_state)
			{
				expend->state->pred = best_state;
				expend->state->g = tmp_g;
				expend->state->f = 0;
				if (!env->greedy)
					expend->state->f += expend->state->g;
				if (!env->uniform)
					expend->state->f += expend->state->h;
				push_list_state(&opened, expend->state);
				push_tree_state(env, &state_tree, expend->state, 1);
				opened_size++;
				tmp = expend;
				expend = expend->next;
				free(tmp);
				continue;
			}
			else if (tmp_g >= tmp_state->g)
			{
				tmp = expend;
				expend = expend->next;
				free_state(env,tmp->state);
				free(tmp);
				continue;
			}
			tmp_state->pred = best_state;
			tmp_state->g = tmp_g;
			tmp_state->f = 0;
			if (!env->greedy)
				tmp_state->f += tmp_state->g;
			if (!env->uniform)
				tmp_state->f += tmp_state->h;
			tmp = expend;
			expend = expend->next;
			free_state(env, tmp->state);
			free(tmp);
		}
	}
	if (success)
	{
		t_state *check = best_state;
		int i = 0;
		while (check) // added a better count number here to check what the best state.
		{
			++i;
			check = check->pred;
		}
		setvbuf(stdout, NULL, _IOFBF, BUFSIZ);
		printf("solution: \n");
		print_solution(env, best_state);
		printf("time complexity: %d\nsize complexity: %d\nnumber of moves: %d\n", complexity_time, complexity_size, i);
		fflush(stdout);
		setvbuf(stdout, NULL, _IOLBF, BUFSIZ);
	}
	else
	{
		ft_putendl("This puzzle is not solvable");
	}
	free_tree_state(env, &state_tree);
	free_list_state(opened);
}
