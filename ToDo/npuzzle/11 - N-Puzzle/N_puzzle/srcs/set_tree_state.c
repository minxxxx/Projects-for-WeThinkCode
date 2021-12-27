/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tree_state.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:24:25 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/15 14:24:25 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void	set_tree_state(t_env *env, t_tree_state *tree, t_state *state, int opened)
{
	t_tree_state *lst;
	int size = env->size * env->size;
	int i = 0;

	lst = tree;
	while (i < size)
	{
		lst = lst->child[state->puzzle[i / env->size][i % env->size]];
		if (!lst)
		{
			ft_putendl("FAILED Damn!");
			exit(EXIT_FAILURE);
			return ;
		}
		++i;
	}
	lst->opened = opened;
}
