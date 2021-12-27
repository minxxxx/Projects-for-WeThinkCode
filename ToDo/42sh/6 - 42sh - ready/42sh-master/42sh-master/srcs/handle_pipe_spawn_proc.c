/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipe_spawn_proc.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static void	init_fd_before_last(t_cmd *cmd, int fd)
{
	if (cmd->fd_in->fd != 0)
	{
		dup2(cmd->fd_in->fd, 0);
		if (cmd->fd_in->fd != -2)
			close(cmd->fd_in->fd);
	}
	if (cmd->fd_out->fd != 1)
	{
		if (cmd->fd_out->fd_pointe == 2)
			dup2(cmd->fd_err->fd, 1);
		else
			dup2(cmd->fd_out->fd, 1);
		if (cmd->fd_out->fd != -2)
			close(cmd->fd_out->fd);
	}
	if (cmd->fd_err->fd != 2)
	{
		if (cmd->fd_err->fd_pointe == 1)
			dup2(fd, 2);
		else
			dup2(cmd->fd_err->fd, 2);
		if (cmd->fd_err->fd != -2)
			close(cmd->fd_err->fd);
	}
}

int			spawn_proc(t_cmd *cmd, t_env *env, t_data *data, int fd)
{
	pid_t	pid;
	char	*file;
	char	**environ;

	if ((pid = fork()) == 0)
	{
		signal(SIGINT, SIG_DFL);
		dup2(fd, cmd->fd_out->fd);
		init_fd_before_last(cmd, fd);
		if (cmd->fd_in->fd == -2)
			close(0);
		if (cmd->fd_out->fd == -2)
			close(1);
		if (cmd->fd_err->fd == -2)
			close(2);
		if (is_builtin(cmd->av[0]))
			exec_builtin_pipe(cmd, &env, data);
		file = find_exec(cmd->av[0], data, env);
		environ = make_env_char(env);
		return (execve(file, cmd->av, environ));
	}
	if (cmd->fd_in->fd != 0)
		close(cmd->fd_in->fd);
	return (pid);
}
