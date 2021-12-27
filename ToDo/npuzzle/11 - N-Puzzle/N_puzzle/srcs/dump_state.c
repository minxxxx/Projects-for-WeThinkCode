/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:27:52 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/09 12:27:53 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*void	dump_state(t_env *env, t_state *state)
{
	int	x;
	int	y;

	y = 0;
	while(y < env->size)
	{
		x = 0;
		while (x < env->size)
		{
			ft_putnbr(state->puzzle[y][x]);
			if (x != env->size -1)
				printf("%d%c", state->puzzle[y][x], x == env->size - 1 ? '\n' : ' ');
			x++;
		}
		y++;
	}
}*/

#include "npuzzle.h"

void	dump_state(t_env *env, t_state *state)
{
	for (int y = 0; y < env->size; ++y) // above code might be better to use rather
	{
		for (int x = 0; x < env->size; ++x)
		{
			printf("%d", state->puzzle[y][x]);
			if (x != env->size - 1)
				printf("%d%c", state->puzzle[y][x], x == env->size - 1 ? '\n' : ' ');
		}
	}
}
