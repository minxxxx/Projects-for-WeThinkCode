/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_void_cases.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 14:45:59 by wide-aze          #+#    #+#             */
/*   Updated: 2015/03/01 14:46:36 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		count_void_cases(t_env *env)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = -1;
	while (++i < env->map_size)
	{
		j = -1;
		while (++j < env->map_size)
		{
			if (env->map[i][j] == 0)
				count++;
		}
	}
	return (count);
}
