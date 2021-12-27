/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tree_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 08:44:54 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/17 08:44:55 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void free_tree_state(t_env *env, t_tree_state *node)
{
	int size = env->size * env->size;
	int i = 0;

	while (i < size)
	{
		if (node->child[i])
			free_tree_state(env, node->child[i]);
		free(node->child[i]);
		++i;
	}
	free(node->child);
	if (node->state)
		free_state(env, node->state);
}
