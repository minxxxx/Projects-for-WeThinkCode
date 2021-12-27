/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <dtedgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:11:18 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/22 11:53:25 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh.h"

void		ft_pipe(t_tree *node, t_env *env_list)
{
	int		fds[2];
	pid_t	pid;
	int		status;

	if (pipe(fds) == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			dup2(fds[1], node->fd_out);
			close(fds[0]);
			ft_choose_exec(node->left, env_list);
		}
		else
		{
			dup2(fds[0], node->fd_in);
			close(fds[1]);
			waitpid(-1, &status, 0);
			ft_choose_exec(node->right, env_list);
		}
	}
	else
	{
		exit(2);
	}
}

void		ft_write(t_tree *node, t_env *env_list)
{
	int		fd;
	pid_t	pid;
	int		status;

	if (node->token == TOKEN_DOUBLE_WRITE)
		fd = open(node->right->cmd[0], O_WRONLY | O_APPEND | O_CREAT,
	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	else
		fd = open(node->right->cmd[0], O_WRONLY | O_TRUNC | O_CREAT,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd, node->fd_out);
		ft_choose_exec(node->left, env_list);
	}
	else
	{
		close(fd);
		waitpid(-1, &status, 0);
		exit(0);
	}
}

void		ft_simple_read(t_tree *node, t_env *env_list)
{
	int		fd;
	pid_t	pid;
	int		status;

	fd = open(node->right->cmd[0], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("No such file or directory: %s\n", node->right->cmd[0]);
		exit(1);
	}
	pid = fork();
	if (pid == 0)
	{
		dup2(fd, node->fd_in);
		ft_choose_exec(node->left, env_list);
	}
	else
	{
		close(fd);
		waitpid(-1, &status, 0);
		exit(0);
	}
}

char		*ft_loop_input(t_tree *node)
{
	char	*end_str;
	char	*line;
	char	*ret;

	line = NULL;
	ret = NULL;
	end_str = node->right->cmd[0];
	while (!line || ft_strcmp(end_str, line) != 0)
	{
		get_next_line(0, &line);
		if (ft_strcmp(end_str, line) == 0)
			break ;
		if (!ret)
			ret = ft_strdup(line);
		else
			ret = ft_strjoin(ret, line);
		ret = ft_strjoin(ret, "\n");
	}
	return (ret);
}

void		ft_double_read(t_tree *node, t_env *env_list)
{
	int		fds[2];
	pid_t	pid;
	int		status;

	if (pipe(fds) == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			dup2(fds[1], node->fd_out);
			close(fds[0]);
			ft_putstr(ft_loop_input(node));
			exit(0);
		}
		else
		{
			dup2(fds[0], node->fd_in);
			close(fds[1]);
			waitpid(-1, &status, 0);
			ft_choose_exec(node->left, env_list);
		}
	}
	else
		exit(2);
}
