/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 10:15:57 by wide-aze          #+#    #+#             */
/*   Updated: 2015/03/01 21:53:45 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		move_nb_left(t_env *env, int *x, int y)
{
	while (*x > 0 && MAP_GET(env, *x, y) > 0
	&& MAP_GET(env, *x - 1, y) == 0)
	{
		MAP_GET(env, *x - 1, y) = MAP_GET(env, *x, y);
		MAP_GET(env, *x, y) = 0;
		(*x)--;
		env->moved = true;
	}
}

static void		merge_if_needed(t_env *env, int x, int y)
{
	if (x > 0 && MAP_GET(env, x, y) > 0
	&& MAP_GET(env, x - 1, y) == MAP_GET(env, x, y) && env->last_merged < x)
	{
		MAP_GET(env, x, y) = 0;
		MAP_GET(env, x - 1, y) *= 2;
		env->score += MAP_GET(env, x - 1, y);
		env->last_merged = x;
		env->moved = true;
	}
}

static void		do_action(t_env *env, int x, int y, int save)
{
	while (++y < env->map_size)
	{
		x = 0;
		env->last_merged = 0;
		while (x <= env->map_size - 1)
		{
			save = x;
			move_nb_left(env, &x, y);
			merge_if_needed(env, x, y);
			x = save + 1;
		}
	}
}

void			action_left(t_env *env)
{
	env->moved = false;
	do_action(env, 0, -1, 0);
	if (env->moved)
		put_rand(env);
}
