/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 11:38:13 by sfranc            #+#    #+#             */
/*   Updated: 2017/09/19 15:17:46 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

/*
** == Grammar (BNF form) ==
** compound_command:	list ((SEMI) list)*
** list: 				pipeline ((AND_IF | OR_IF) pipeline)*
** pipeline: 			simple_command ((PIPE) simple_command)*
** simple_command:		(WORD)+ (REDIRECT WORD)*
*/

/*
** Within a same level of precedence, check to see if there is another occurence
** of a sign of the precedence level (see grammar).
** If so, built the tree upward, the actual node is the left wing.
** Else, finish building the tree down to the right.
*/

t_ast	*ft_create_pipeline(t_token **token)
{
	t_ast	*root;

	root = ft_create_leaf(token, OPERATOR);
	if ((*token)->operator_type == PIPE)
	{
		if (ft_check_next_operator(*token, PIPE))
		{
			while ((*token)->operator_type == PIPE)
			{
				root = ft_create_node(root, ft_create_leaf(token, WORD),\
						ft_create_leaf(token, OPERATOR));
			}
		}
		else
			root = ft_create_node(root, ft_create_leaf(token, WORD),\
					ft_create_leaf(token, OPERATOR));
	}
	return (root);
}

t_ast	*ft_create_list(t_token **token)
{
	t_ast	*root;

	root = ft_create_pipeline(token);
	if ((*token)->operator_type == AND_IF || (*token)->operator_type == OR_IF)
	{
		if (ft_check_next_operator(*token, AND_IF)\
				|| ft_check_next_operator(*token, OR_IF))
		{
			while ((*token)->operator_type == AND_IF\
					|| (*token)->operator_type == OR_IF)
			{
				root = ft_create_node(root, ft_create_leaf(token, WORD),\
						ft_create_pipeline(token));
			}
		}
		else
		{
			root = ft_create_node(root, ft_create_leaf(token, WORD),\
					ft_create_pipeline(token));
		}
	}
	return (root);
}

t_ast	*ft_create_ast(t_token **token)
{
	t_ast	*root;

	root = ft_create_list(token);
	if ((*token)->operator_type == SEMI)
	{
		if (ft_check_next_operator(*token, SEMI))
		{
			while ((*token)->operator_type == SEMI)
			{
				root = ft_create_node(root, ft_create_leaf(token, WORD),\
						ft_create_list(token));
			}
		}
		else
		{
			root = ft_create_node(root, ft_create_leaf(token, WORD),\
					ft_create_list(token));
		}
	}
	return (root);
}
