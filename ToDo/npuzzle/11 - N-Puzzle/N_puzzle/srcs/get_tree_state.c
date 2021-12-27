/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tree_state.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:22:24 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/15 14:22:25 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

t_state	*get_tree_state(t_env *env, t_tree_state *tree, t_state *state, int *is_closed)
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
			return (NULL);
		}
		++i;
	}
	if (is_closed)
		*is_closed = !lst->opened;
	return (lst->state);
}
