/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_score_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:20:00 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/15 09:20:04 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void	cal_score_state(t_env *env, t_state *state)
{
	state->h = get_score(env, state, env->end);
	state->f = state->g + state->h;
}
