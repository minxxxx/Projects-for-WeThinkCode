/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:35:41 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/14 17:35:42 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

t_state *copy_state(t_env *env, t_state *from)
{
	t_state *state;

	state = new_size_state(env);
	for (int y = 0; y < env->size; ++y)
	{
		for (int x = 0; x < env->size; ++x)
		{
			state->puzzle[y][x] = from->puzzle[y][x];
		}
	}
	state->h = from->h;
	return (state);
}
