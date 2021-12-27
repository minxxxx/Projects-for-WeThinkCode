/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	exec_cmd_2(t_env **env, t_cmd **command, t_data *data)
{
	int		ret;
	pid_t	pid;

	pid = fork();
	if (pid != 0)
	{
		waitpid(pid, &ret, 0);
		(*command)->ret = get_ret(ret, data);
		data->ret = ret;
	}
	else
	{
		signal(SIGINT, SIG_DFL);
		fork_pipes((*command), *env, data);
		exit(1);
	}
	while ((*command) && (*command)->sep == '|')
		(*command) = (*command)->next;
	if ((*command))
	{
		(*command) = (*command)->next;
		if ((*command))
			(*command) = cmd_not_found((*command), data, *env);
	}
}

void	exec_cmd_1(t_env **env, t_cmd **command, t_data *data, int tmp)
{
	if (is_builtin((*command)->av[0]))
	{
		(*command)->ret = exec_builtin((*command), env, data);
		data->ret = (*command)->ret;
	}
	else
	{
		exec_file((*command), *env, data->in_env_i, data);
		(*command)->ret = get_ret((*command)->ret, data);
	}
	tmp = 0;
	if ((*command)->fd_out->next || (*command)->fd_err->next ||\
			(*command)->fd_in->next)
	{
		tmp = 1;
		if ((*command)->fd_in->next)
			(*command)->fd_in = (*command)->fd_in->next;
		if ((*command)->fd_out->next)
			(*command)->fd_out = (*command)->fd_out->next;
		if ((*command)->fd_err->next)
			(*command)->fd_err = (*command)->fd_err->next;
	}
	if (!tmp)
		(*command) = (*command)->next;
}

void	exec_cmd(t_env **env, t_cmd *command, t_data *data)
{
	t_cmd	*temp;
	t_fd	*fd_save[3];

	if (!command)
		return ;
	temp = command;
	fd_save[0] = command->fd_in;
	fd_save[1] = command->fd_out;
	fd_save[2] = command->fd_err;
	command = cmd_not_found(command, data, *env);
	while (command)
	{
		if (command->av[0] && (command->sep == NONE ||\
					command->sep == POINT_VIRGULE || command->sep == ETET ||\
					command->sep == OUOU))
			exec_cmd_1(env, &command, data, 0);
		else if (command->sep == '|')
			exec_cmd_2(env, &command, data);
	}
	temp->fd_in = fd_save[0];
	temp->fd_out = fd_save[1];
	temp->fd_err = fd_save[2];
	close_fd_cmd(temp);
}
