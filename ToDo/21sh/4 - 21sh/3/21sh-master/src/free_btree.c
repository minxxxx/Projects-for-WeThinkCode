/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_btree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:58:38 by fkoehler          #+#    #+#             */
/*   Updated: 2016/09/20 16:18:42 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	free_redirs(t_redir **redirs)
{
	t_redir	*tmp1;
	t_redir	*tmp2;

	if (!(tmp1 = *redirs))
		return ;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		free(tmp1->s);
		free(tmp1);
		tmp1 = tmp2;
	}
	*redirs = NULL;
}

void	free_btree(t_btree *tree)
{
	if (!tree)
		return ;
	if (tree->left)
		free_btree(tree->left);
	if (tree->right)
		free_btree(tree->right);
	if (tree->type == CMD)
	{
		free(tree->str);
		if (tree->redir)
			free_redirs(&(tree->redir));
	}
	free(tree);
}
