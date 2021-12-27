/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 18:05:21 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static int	find_number(t_cmd *cmd)
{
	int		n;

	n = 1;
	while (cmd && cmd->sep == '|')
	{
		n++;
		cmd = cmd->next;
	}
	return (n);
}

static int	exec_all_except_last(t_cmd **cmd, t_env *env, t_data *data)
{
	int		i;
	int		n;
	int		fd[2];

	i = 0;
	n = find_number(*cmd);
	while (i < n - 1)
	{
		pipe(fd);
		if ((*cmd)->fd_out->fd == -2)
			close(fd[1]);
		spawn_proc(*cmd, env, data, fd[1]);
		close(fd[1]);
		*cmd = (*cmd)->next;
		if (*cmd == NULL)
		{
			ft_putstr_fd("42sh: parse error near '|'\n", 2);
			return (0);
		}
		(*cmd)->fd_in->fd = fd[0];
		i++;
	}
	return (1);
}

static void	init_fd_for_last(t_cmd *cmd)
{
	if (cmd->fd_in->fd != 0)
		dup2(cmd->fd_in->fd, 0);
	if (!cmd->fd_out || cmd->fd_out->fd == -2)
		close(1);
	else if (cmd->fd_out->fd != 1)
		dup2(cmd->fd_out->fd, 1);
	if (!cmd->fd_err || cmd->fd_err->fd == -2)
		close(2);
	else if (cmd->fd_err->fd != 2)
		dup2(cmd->fd_err->fd, 2);
}

void		exec_builtin_pipe(t_cmd *cmd, t_env **env, t_data *data)
{
	cmd->fd_in->fd = 0;
	cmd->fd_out->fd = 1;
	cmd->fd_err->fd = 2;
	cmd->ret = exec_builtin(cmd, env, data);
	exit(cmd->ret);
}

int			fork_pipes(t_cmd *cmd, t_env *env, t_data *data)
{
	char	*file;
	char	**environ;
	int		fork_exec;
	int		ret_execve;

	if (!exec_all_except_last(&cmd, env, data))
		return (-1);
	init_fd_for_last(cmd);
	fork_exec = fork();
	if (fork_exec != 0)
		waitpid(fork_exec, &ret_execve, 0);
	else
	{
		if (is_builtin(cmd->av[0]))
			exec_builtin_pipe(cmd, &env, data);
		file = find_exec(cmd->av[0], data, env);
		environ = make_env_char(env);
		ret_execve = 0;
		return (execve(file, cmd->av, environ));
	}
	wait(NULL);
	exit(get_ret(ret_execve, data));
}
