/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equals_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:38:08 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/14 17:38:09 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int equals_state(t_env *env, t_state *s1, t_state *s2)
{
	if (s1->h != s2->h)
		return (0);
	for (int y = 0; y < env->size; ++y)
	{
		for (int x = 0; x < env->size; ++x)
		{
			if (s1->puzzle[y][x] != s2->puzzle[y][x])
				return (0);
		}
	}
	return (1);
}
