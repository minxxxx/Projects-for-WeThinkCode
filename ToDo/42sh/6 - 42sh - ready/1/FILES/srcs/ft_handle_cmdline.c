/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_cmdline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <dtedgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:10:16 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/22 20:42:15 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh.h"

t_tree	**ft_split_and_build(void)
{
	int				i;
	char			**split;
	t_tree			**cmd_tree;

	i = 0;
	split = ft_strsplit(g_main_line.cmd, ';');
	cmd_tree = (t_tree **)malloc(sizeof(t_tree *) * ft_tablen(split) + 1);
	while (split[i])
	{
		cmd_tree[i] = ft_build_tree(split[i]);
		i++;
	}
	cmd_tree[i] = NULL;
	return (cmd_tree);
}

int		ft_handle_cmdline(t_env *env_list)
{
	t_tree			**cmd_tree;
	int				i;

	if (g_main_line.cmd[0] == '{' || g_main_line.cmd[0] == '(')
		g_main_line.cmd = ft_parentheses();
	else
		g_main_line.cmd = ft_handle_quote();
	cmd_tree = ft_split_and_build();
	i = 0;
	while (cmd_tree[i])
	{
		ft_exec_tree(cmd_tree[i], env_list);
		i++;
	}
	return (0);
}
