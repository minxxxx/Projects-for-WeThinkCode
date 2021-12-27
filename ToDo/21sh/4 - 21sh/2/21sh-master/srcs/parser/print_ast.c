/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 12:07:39 by sfranc            #+#    #+#             */
/*   Updated: 2017/09/19 15:14:15 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

void	ft_padding(int padd)
{
	int	i;

	i = 0;
	while (++i < padd)
		write(1, "\t", 1);
}

void	ft_print_node(t_ast *ast, char *side, int lvl)
{
	t_token *tmp;

	ft_padding(lvl);
	ft_putstr("** ");
	ft_putstr(side);
	ft_putnbr(lvl);
	ft_putendl(" **");
	ft_padding(lvl);
	tmp = ast->token;
	ft_putstr(BMAGENTA);
	while (tmp)
	{
		ft_putstr(tmp->str);
		ft_putstr(" ");
		tmp = tmp->next;
	}
	ft_putendl(RESET);
	ft_padding(lvl);
	ft_putendl("************");
}

void	ft_print_ast(t_ast *ast, char *side, int lvl)
{
	if (lvl == 0)
		ft_putendl(BMAGENTA"________________ AST ________________"RESET);
	if (!ast)
		return ;
	if (ast->left)
		ft_print_ast(ast->left, "left", ++lvl);
	else
		++lvl;
	ft_print_node(ast, side, lvl);
	if (ast->right)
		ft_print_ast(ast->right, "right", lvl--);
	else
		--lvl;
	if (lvl == 0)
		ft_putendl(BMAGENTA"_____________________________________"RESET);
}
