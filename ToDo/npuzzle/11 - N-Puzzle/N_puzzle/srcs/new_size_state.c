/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_size_state.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 06:51:30 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/15 06:51:31 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

t_state *new_size_state(t_env *env)
{
	t_state *state;

	state = new_state();
	if (!(state->puzzle = malloc(sizeof(*state->puzzle) * env->size)))
	{
		ft_putendl_fd("npuzzle: failed to malloc new state puzzle", 2);
		exit(EXIT_FAILURE);
	}
	//int i = 0;
	// if you want to use the while then uncomment the commented code
	for (int i = 0; i < env->size; i++)//while (i < env->size)
	{
		if (!(state->puzzle[i] = malloc(sizeof(*state->puzzle[i]) * env->size)))
		{
			ft_putendl_fd("npuzzle: failed to malloc new state puzzle", 2);
			exit(EXIT_FAILURE);
		}
		//int j = 0;
		for (int j = 0; j < env->size; j++)//while (j < env->size)
		{
			state->puzzle[i][j] = 0;
			//j++;
		}
		//i++;
	}
	return (state);
}
