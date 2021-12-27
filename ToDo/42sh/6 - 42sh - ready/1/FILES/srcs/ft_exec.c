/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <dtedgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 10:58:34 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/26 15:50:16 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh.h"

char		*ft_str_replace(char *origin, char *rep, char *with)
{
	char	*start;
	size_t	size_rep;
	char	*new;

	if (!(start = ft_strstr(origin, rep)))
		return (origin);
	size_rep = ft_strlen(rep);
	new = ft_strnew(ft_strlen(origin) - ft_strlen(rep) + ft_strlen(with));
	ft_strncpy(new, origin, start - origin);
	ft_strcat(new, with);
	ft_strcat(new, start + size_rep);
	return (new);
}

void		change_fd(t_tree *node)
{
	if (node->from != -2 && node->to != -2)
	{
		if (node->to != -1)
			dup2(node->to, node->from);
		else
			close(node->from);
	}
}

int			ft_exec_cmd(t_tree *node, t_env *env_list)
{
	char	*path;

	if (builtin_commands(node->cmd[0], node->cmd, &env_list))
		exit(0);
	if (!env_list)
		return (0);
	change_fd(node);
	if ((path = find_command(ft_tolower(node->cmd[0]), env_list)))
		execve(path, node->cmd, NULL);
	else
		ft_putstr("Command not found!\n");
	return (0);
}

void		ft_choose_exec(t_tree *node, t_env *env_list)
{
	if (node->token == TOKEN_CMD)
		ft_exec_cmd(node, env_list);
	else if (node->token == TOKEN_AND)
		ft_and(node, env_list);
	else if (node->token == TOKEN_OR)
		ft_or(node, env_list);
	else if (node->token == TOKEN_PIPE)
		ft_pipe(node, env_list);
	else if (node->token == TOKEN_SIMPLE_WRITE
			|| node->token == TOKEN_DOUBLE_WRITE)
		ft_write(node, env_list);
	else if (node->token == TOKEN_SIMPLE_READ)
		ft_simple_read(node, env_list);
	else if (node->token == TOKEN_DOUBLE_READ)
		ft_double_read(node, env_list);
}

int			ft_exec_tree(t_tree *node, t_env *env_list)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		ft_choose_exec(node, env_list);
		return (0);
	}
	else
	{
		waitpid(-1, &status, 0);
		if (node->token == TOKEN_CMD)
		{
			if (ft_strcmp(node->cmd[0], "exit") == 0)
				handle_ctrl_d();
			if (ft_strcmp(node->cmd[0], "cd") == 0)
				builtin_commands(node->cmd[0], node->cmd, &env_list);
		}
		return (0);
	}
}
