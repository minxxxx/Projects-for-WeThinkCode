/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_fd_redirection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <dtedgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:10:30 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/22 11:53:17 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh.h"

void	ft_assign_fd_change(t_tree *node, char *str, size_t k)
{
	node->from = ft_atoi(str);
	node->to = ft_atoi(&str[k]);
}

int		ft_search_redirection(t_tree *node, char *str)
{
	size_t	i;
	size_t	k;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (i == 0)
		return (0);
	if (str[i] != '>' && str[i] != '<')
		return (0);
	i += 2;
	k = i;
	if (str[i] == '-' && str[i + 1] == '\0')
	{
		node->from = ft_atoi(str);
		node->to = -1;
		return (1);
	}
	while (ft_isdigit(str[i]))
		i++;
	if (i < ft_strlen(str) || i == k)
		return (0);
	ft_assign_fd_change(node, str, k);
	return (1);
}

void	ft_handle_fd_redirection(t_tree *node)
{
	char	**cmd;
	int		i;
	size_t	len;

	i = 0;
	cmd = node->cmd;
	while (cmd && cmd[i])
	{
		if (ft_search_redirection(node, node->cmd[i]))
		{
			len = ft_tablen(cmd);
			ft_strdel(&cmd[i]);
			ft_remove_null(cmd, len);
		}
		else
			i++;
	}
}
