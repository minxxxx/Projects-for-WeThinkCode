/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 11:01:55 by sfranc            #+#    #+#             */
/*   Updated: 2017/10/04 11:48:36 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

int				ft_execute_pipeline(t_ast *ast)
{
	if (!ast->left)
		return (ft_launch_pipeline(ast, ast->parent->right));
	else
		return (ft_execute_pipeline(ast->left));
}

static int		ft_execute_semi_list(t_ast *ast)
{
	ft_execute(ast->left);
	return (ft_execute(ast->right));
}

static int		ft_execute_andif_list(t_ast *ast)
{
	if (ft_execute(ast->left) == EXIT_SUCCESS)
		return (ft_execute(ast->right));
	else
		return (EXIT_SUCCESS);
}

static int		ft_execute_orif_list(t_ast *ast)
{
	if (ft_execute(ast->left) != EXIT_SUCCESS)
		return (ft_execute(ast->right));
	else
		return (EXIT_SUCCESS);
}

int				ft_execute(t_ast *ast)
{
	if (!ast)
		return (EXIT_SUCCESS);
	if (ast->operator_type == SEMI)
		return (ft_execute_semi_list(ast));
	else if (ast->operator_type == AND_IF)
		return (ft_execute_andif_list(ast));
	else if (ast->operator_type == OR_IF)
		return (ft_execute_orif_list(ast));
	else if (ast->operator_type == PIPE)
		return (ft_execute_pipeline(ast));
	else if (ast->node_type != OPERATOR)
		return (ft_launch_simple_cmd(ast));
	else
		return (EXIT_SUCCESS);
}
