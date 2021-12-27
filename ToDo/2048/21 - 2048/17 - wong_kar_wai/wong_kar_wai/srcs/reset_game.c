/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:23:30 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/01 19:55:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		clear_map(t_env *env)
{
	int				i;

	i = -1;
	while (++i < env->map_size)
		ft_bzero(env->map[i], S(int, env->map_size));
}

void			reset_game(t_env *env)
{
	clear_map(env);
	env->score = 0;
	env->win = false;
	env->moved = false;
	env->last_merged = false;
	put_rand(env);
	put_rand(env);
	start_game(env);
}
