/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_rand.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 10:40:30 by wide-aze          #+#    #+#             */
/*   Updated: 2015/03/01 20:44:10 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int		spawn_extra(t_env *env)
{
	int		pow;
	int		nb;

	pow = ft_rand(1, env->spawn_max);
	nb = 1;
	while (pow--)
		nb *= 2;
	return (nb);
}

static void		put_one_rand(t_env *env)
{
	int		nb;
	int		pos;
	int		i;
	int		j;

	if ((nb = count_void_cases(env)) == 0)
		return ;
	pos = ft_rand(0, nb - 1);
	i = -1;
	while (++i < env->map_size)
	{
		j = -1;
		while (++j < env->map_size)
		{
			if (env->map[i][j] == 0)
			{
				if (pos == 0)
				{
					env->map[i][j] = ft_randbool(0.5) ? spawn_extra(env) : 2;
					return ;
				}
				pos--;
			}
		}
	}
}

void			put_rand(t_env *env)
{
	int		i;

	i = -1;
	while (++i < env->nb_rand)
		put_one_rand(env);
}
