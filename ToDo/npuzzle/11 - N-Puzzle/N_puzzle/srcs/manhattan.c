/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manhattan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:27:52 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/14 17:27:53 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static int get_diff(t_env *env, t_state *state, int ax, int ay, int val)
{
	for (int y = 0; y < env->size; ++y)
	{
		for (int x = 0; x < env->size; ++x)
		{
			if (state->puzzle[y][x] == val)
				return (abs(x - ax) + abs(y - ay));
		}
	}
	return (0);
}

int manhattan(t_env *env, t_state *s1, t_state *s2)
{
	int total = 0;

	for (int y = 0; y < env->size; ++y)
	{
		for (int x = 0; x < env->size; ++x)
		{
			total += get_diff(env, s2, x, y, s1->puzzle[y][x]);
		}
	}
	return (total);
}
