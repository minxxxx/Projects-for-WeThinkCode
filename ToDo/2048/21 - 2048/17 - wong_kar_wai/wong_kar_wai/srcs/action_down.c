/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:35:44 by wide-aze          #+#    #+#             */
/*   Updated: 2015/03/01 21:55:08 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		move_nb_down(t_env *env, int x, int *y)
{
	while (*y < env->map_size - 1 && MAP_GET(env, x, *y) > 0
	&& MAP_GET(env, x, *y + 1) == 0)
	{
		MAP_GET(env, x, *y + 1) = MAP_GET(env, x, *y);
		MAP_GET(env, x, *y) = 0;
		(*y)++;
		env->moved = true;
	}
}

static void		merge_if_needed(t_env *env, int x, int y)
{
	if (y < env->map_size - 1 && MAP_GET(env, x, y) > 0
	&& MAP_GET(env, x, y + 1) == MAP_GET(env, x, y) && env->last_merged > y)
	{
		MAP_GET(env, x, y) = 0;
		MAP_GET(env, x, y + 1) *= 2;
		env->score += MAP_GET(env, x, y + 1);
		env->last_merged = y;
		env->moved = true;
	}
}

static void		do_action(t_env *env, int x, int y, int save)
{
	while (++x < env->map_size)
	{
		y = env->map_size - 1;
		env->last_merged = env->map_size - 1;
		while (y >= 0)
		{
			save = y;
			move_nb_down(env, x, &y);
			merge_if_needed(env, x, y);
			y = save - 1;
		}
	}
}

void			action_down(t_env *env)
{
	env->moved = false;
	do_action(env, -1, 0, 0);
	if (env->moved)
		put_rand(env);
}
