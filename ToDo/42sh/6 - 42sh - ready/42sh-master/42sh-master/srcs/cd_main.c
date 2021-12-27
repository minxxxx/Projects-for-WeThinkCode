/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static char		*get_cwd_end(t_data *data)
{
	putstr_builtin(data->cd_cmd, BUF_CWD_ERR, 2);
	data->cd_ret = 1;
	return (NULL);
}

static char		*get_cwd(size_t size, t_data *data, char *cwd, char *buf_cwd)
{
	if (size > BUF_CWD)
	{
		if (size < BUF_CWD_MAX)
			size = size * 2;
		else
		{
			data->cd_ret = 1;
			putstr_builtin(data->cd_cmd, BUF_CWD_ERR, 2);
		}
	}
	if ((buf_cwd = (char *)mallocp(sizeof(char) * size)))
	{
		if ((cwd = getcwd(buf_cwd, size)))
			return (cwd);
		else
		{
			free(buf_cwd);
			return (get_cwd(++size, data, NULL, NULL));
		}
	}
	else
		return (get_cwd_end(data));
}

int				cd(char **command, t_env **env, t_data *data, t_cmd *cmd)
{
	char *cwd;

	data->cd_ret = 0;
	data->cd_cmd = cmd;
	if (!is_legal_options(command, cmd, data))
		return (1);
	cwd = get_cwd(BUF_CWD, data, NULL, NULL);
	if (!cwd)
		return (1);
	if (is_goto_home(command))
		go_to_home_directory(env, data);
	else if (is_logical_goto_oldpwd(command))
		go_to_old_pwd(data, env, 0);
	else if (is_physical_goto_oldpwd(command))
		go_to_old_pwd(data, env, 1);
	else if (ft_strcmp(command[1], "-P") == 0)
		change_dir(command[2], env, data, 1);
	else if (ft_strcmp(command[1], "-L") == 0)
		change_dir(command[2], env, data, 0);
	else
		change_dir(command[1], env, data, 0);
	free(cwd);
	return (data->cd_ret);
}
