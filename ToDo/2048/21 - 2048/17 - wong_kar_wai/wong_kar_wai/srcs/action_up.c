/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 10:15:47 by wide-aze          #+#    #+#             */
/*   Updated: 2015/03/01 21:53:49 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		move_nb_up(t_env *env, int x, int *y)
{
	while (*y > 0 && MAP_GET(env, x, *y) > 0
	&& MAP_GET(env, x, *y - 1) == 0)
	{
		MAP_GET(env, x, *y - 1) = MAP_GET(env, x, *y);
		MAP_GET(env, x, *y) = 0;
		(*y)--;
		env->moved = true;
	}
}

static void		merge_if_needed(t_env *env, int x, int y)
{
	if (y > 0 && MAP_GET(env, x, y) > 0
	&& MAP_GET(env, x, y - 1) == MAP_GET(env, x, y) && env->last_merged < y)
	{
		MAP_GET(env, x, y) = 0;
		MAP_GET(env, x, y - 1) *= 2;
		env->score += MAP_GET(env, x, y - 1);
		env->last_merged = y;
		env->moved = true;
	}
}

static void		do_action(t_env *env, int x, int y, int save)
{
	while (++x < env->map_size)
	{
		y = 0;
		env->last_merged = 0;
		while (y <= env->map_size - 1)
		{
			save = y;
			move_nb_up(env, x, &y);
			merge_if_needed(env, x, y);
			y = save + 1;
		}
	}
}

void			action_up(t_env *env)
{
	env->moved = false;
	do_action(env, -1, 0, 0);
	if (env->moved)
		put_rand(env);
}
