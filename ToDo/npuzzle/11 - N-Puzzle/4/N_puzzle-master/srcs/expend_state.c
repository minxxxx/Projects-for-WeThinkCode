/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 06:35:54 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/15 06:35:54 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

t_state_list *expend_state(t_env *env, t_state *state)
{
	t_state_list *lst = NULL;
	t_state *new_tmp;
	int y = 0;
	int x = 0;

	for (y = 0; y < env->size; ++y)
	{
		for (x = 0; x < env->size; ++x)
		{
			if (state->puzzle[y][x] == 0)
				goto expend;
		}
	}
expend:
	if (y != 0)
	{
		new_tmp = copy_state(env, state);
		new_tmp->puzzle[y][x] = new_tmp->puzzle[y - 1][x];
		new_tmp->puzzle[y - 1][x] = 0;
		cal_score_state(env, new_tmp);
		push_list_state(&lst, new_tmp);
	}
	if (y != env->size - 1)
	{
		new_tmp = copy_state(env, state);
		new_tmp->puzzle[y][x] = new_tmp->puzzle[y + 1][x];
		new_tmp->puzzle[y + 1][x] = 0;
		cal_score_state(env, new_tmp);
		push_list_state(&lst, new_tmp);
	}
	if (x != 0)
	{
		new_tmp = copy_state(env, state);
		new_tmp->puzzle[y][x] = new_tmp->puzzle[y][x - 1];
		new_tmp->puzzle[y][x - 1] = 0;
		cal_score_state(env, new_tmp);
		push_list_state(&lst, new_tmp);
	}
	if (x != env->size - 1)
	{
		new_tmp = copy_state(env, state);
		new_tmp->puzzle[y][x] = new_tmp->puzzle[y][x + 1];
		new_tmp->puzzle[y][x + 1] = 0;
		cal_score_state(env, new_tmp);
		push_list_state(&lst, new_tmp);
	}
	return (lst);
}
