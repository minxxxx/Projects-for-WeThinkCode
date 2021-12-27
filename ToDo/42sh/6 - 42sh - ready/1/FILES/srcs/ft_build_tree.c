/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <dtedgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:09:05 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/22 11:53:10 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh.h"

char	**ft_separate_cmd(char *cmd, t_token_info *token_info)
{
	char	**cmds;

	if ((cmds = (char **)malloc(sizeof(char *) * 3)))
	{
		if (token_info->type == TOKEN_DOUBLE_WRITE ||
			token_info->type == TOKEN_DOUBLE_READ ||
			token_info->type == TOKEN_AND ||
			token_info->type == TOKEN_OR)
			cmds[0] = ft_strndup(cmd, (size_t)token_info->pos - 1);
		else
			cmds[0] = ft_strndup(cmd, (size_t)token_info->pos);
		cmds[1] = ft_strdup(&cmd[token_info->pos + 1]);
		cmds[2] = NULL;
	}
	return (cmds);
}

void	ft_build_recursive(t_tree *node, char *cmd, t_token_info *token_info)
{
	char	**cmds;

	node->cmd = NULL;
	cmds = ft_separate_cmd(cmd, token_info);
	node->left = ft_build_tree(cmds[0]);
	node->right = ft_build_tree(cmds[1]);
	free(cmds);
}

void	ft_build_simple_cmd(t_tree *node, char *cmd)
{
	node->cmd = ft_strsplit(cmd, ' ');
	ft_handle_fd_redirection(node);
	node->left = NULL;
	node->right = NULL;
}

t_tree	*ft_build_tree(char *cmd_line)
{
	t_tree				*node;
	t_token_info		token_info;

	if ((node = (t_tree *)malloc(sizeof(t_tree))))
	{
		ft_find_operator(cmd_line, &token_info);
		node->token = token_info.type;
		node->fd_in = 0;
		node->fd_out = 1;
		if (node->token == TOKEN_CMD)
			ft_build_simple_cmd(node, cmd_line);
		else
			ft_build_recursive(node, cmd_line, &token_info);
	}
	return (node);
}
