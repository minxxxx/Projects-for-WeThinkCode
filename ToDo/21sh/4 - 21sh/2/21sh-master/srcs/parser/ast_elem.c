/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 12:08:48 by sfranc            #+#    #+#             */
/*   Updated: 2017/09/19 15:13:16 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

int		ft_check_next_operator(t_token *token, int op)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		if (tmp->operator_type == op)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_ast	*ft_create_leaf(t_token **token, int delim)
{
	t_ast	*new;
	t_token	*tmp;

	if ((*token)->token_type == NEWLINE)
		return (NULL);
	new = ft_memalloc(sizeof(t_ast));
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	new->node_type = (*token)->token_type;
	new->operator_type = (*token)->operator_type;
	new->token = *token;
	tmp = (*token)->next;
	while (tmp->next && tmp->token_type != delim)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	*token = tmp;
	return (new);
}

t_ast	*ft_create_node(t_ast *left, t_ast *node, t_ast *right)
{
	node->left = left;
	node->right = right;
	if (left)
		left->parent = node;
	if (right)
		right->parent = node;
	return (node);
}

void	ft_del_ast(t_ast **ast)
{
	if (!*ast)
		return ;
	ft_del_ast(&(*ast)->left);
	ft_del_ast(&(*ast)->right);
	ft_deltokens(&(*ast)->token);
	free(*ast);
	*ast = NULL;
}
