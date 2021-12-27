/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 06:39:13 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/15 06:39:14 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void free_state(t_env *env, t_state *state)
{
	for (int y = 0; y < env->size; ++y)
	{
		free(state->puzzle[y]);
	}
	free(state->puzzle);
	free(state);
}
