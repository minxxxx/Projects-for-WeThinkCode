/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			verif_exec_file(t_cmd *cmd, int in_env_i, char *file)
{
	DIR		*dir;

	if (access(file, X_OK) == -1)
	{
		if (in_env_i)
			ft_putstr_fd("env: permission denied: ", 2);
		else
			ft_putstr_fd("42sh: permission denied: ", 2);
		ft_putendl_fd(cmd->av[0], 2);
		free(file);
		return (0);
	}
	dir = opendir(file);
	if (dir)
	{
		if (in_env_i)
			ft_putstr_fd("env: permission denied: ", 2);
		else
			ft_putstr_fd("42sh: permission denied: ", 2);
		ft_putendl_fd(cmd->av[0], 2);
		free(file);
		closedir(dir);
		return (0);
	}
	return (1);
}

char		**init_array_env(t_env *list, int in_env_i)
{
	char	**env;

	if (in_env_i)
		env = make_env_char(NULL);
	else
		env = make_env_char(list);
	return (env);
}

void		verif_fd(t_cmd *cmd)
{
	if (!cmd->fd_in || cmd->fd_in->fd == -2)
		close(0);
	else if (cmd->fd_in->fd != 0)
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

int			failure_exec(t_cmd *cmd, char **env, int in_env_i, char *file)
{
	int		retour;

	retour = execve(file, cmd->av, env);
	if (retour == -1)
	{
		if (in_env_i)
			ft_putstr_fd("env: exec format error: ", 2);
		else
			ft_putstr_fd("42sh: exec format error: ", 2);
		ft_putendl_fd(cmd->av[0], 2);
		return (1);
	}
	return (0);
}

int			exec_file(t_cmd *cmd, t_env *list, int in_env_i, t_data *data)
{
	char	*file;
	char	**env;
	pid_t	process;

	file = find_exec(cmd->av[0], data, list);
	if (!file || !verif_exec_file(cmd, in_env_i, file))
		return (0);
	env = init_array_env(list, in_env_i);
	process = fork();
	if (process != 0)
		wait(&cmd->ret);
	else
	{
		verif_fd(cmd);
		signal(SIGINT, SIG_DFL);
		if (failure_exec(cmd, env, in_env_i, file))
			exit(EXIT_FAILURE);
		exit(EXIT_SUCCESS);
	}
	free(file);
	free_char_tab(env);
	return (1);
}
