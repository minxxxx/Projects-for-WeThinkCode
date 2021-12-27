/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misplaced.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:28:54 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/14 17:28:55 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int		misplaced(t_env *env, t_state *s1, t_state *s2)
{
	int total;
	//int y;
	//int x;

	total = 0;
	//y = 0;
	for (int y = 0; y < env->size; y++)//while (y < env->size) 
	{
		//x = 0;
		for (int x = 0; x < env->size; x++)//while (x < env->size)
		{
			if (s1->puzzle[y][x] != 0 && s1->puzzle[y][x] != s2->puzzle[y][x])
				++total;
			//x++;
		}
		//y++;
	}
	return (total);
}
