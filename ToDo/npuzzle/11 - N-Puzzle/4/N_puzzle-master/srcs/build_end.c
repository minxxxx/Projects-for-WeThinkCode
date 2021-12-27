/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:03:09 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/14 15:03:10 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

static void build_odd(t_env *env)
{
	int i;
	int x;
	int y;
	int z;

	i = 1;
	z = 0;
	while (z < env->size / 2)
	{
		x = z;
		y = z;
		while (x < env->size - z)
		{
			env->end->puzzle[y][x] = i;
			i++;
			x++;
		}
		x--;
		while (++y < env->size - z)
		{
			env->end->puzzle[y][x] = i;
			i++;
		}
		y--;
		while (--x >= z)
		{
			env->end->puzzle[y][x] = i;
			i++;
		}
		x++;
		while (--y > z)
		{
			env->end->puzzle[y][x] = i;
			i++;
		}
		z++;
	}
}

static void build_even(t_env *env)
{
	int i;
	int x;
	int y;
	int z;

	i = 1;
	z = 0;
	while (z < env->size / 2 - 1)
	{
		x = z;
		y = z;
		while (x < env->size - z)
		{
			env->end->puzzle[y][x] = i;
			i++;
			x++;
		}
		x--;
		while (++y < env->size - z)
		{
			env->end->puzzle[y][x] = i;
			i++;
		}
		y--;
		while (--x >= z)
		{
			env->end->puzzle[y][x] = i;
			i++;
		}
		x++;
		while (--y > z)
		{
			env->end->puzzle[y][x] = i;
			i++;
		}
		z++;
	}
	env->end->puzzle[env->size / 2 - 1][env->size / 2 - 1] = i++;
	env->end->puzzle[env->size / 2 - 1][env->size / 2] = i++;
	env->end->puzzle[env->size / 2][env->size / 2] = i++;
}

void build_end(t_env *env)
{
	if (env->size % 2 == 1)
	{
		build_odd(env);
	}
	else
	{
		build_even(env);
	}
}
