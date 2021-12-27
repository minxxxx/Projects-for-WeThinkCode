/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 16:29:24 by sfranc            #+#    #+#             */
/*   Updated: 2017/10/14 19:09:27 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

static int	ft_launch_cmd_env(char **cmd, int i, char **exec_env)
{
	char	**new_cmd;
	char	*path;
	int		ret_cmd;

	ret_cmd = EXIT_SUCCESS;
	new_cmd = NULL;
	while (cmd[i])
		ft_addtotab(&new_cmd, cmd[i++]);
	if (!new_cmd)
	{
		if (exec_env)
			ft_puttab(exec_env);
		return (ret_cmd);
	}
	if (ft_is_builtin(new_cmd[0]))
		ret_cmd = ft_launch_builtin(new_cmd);
	else if ((ret_cmd = ft_get_path(new_cmd[0], &path)) == PATH_OK)
	{
		ret_cmd = ft_fork(path, new_cmd);
		free(path);
	}
	ft_freetab(&new_cmd);
	return (ret_cmd);
}

static int	ft_create_exec_env(char **cmd, char ***exec_env)
{
	int		i;

	i = 1;
	if (!ft_strequ(cmd[i], "-i"))
		*exec_env = ft_tabdup(g_shell->env);
	else
		++i;
	while (cmd[i] && ft_strchr(cmd[i], '='))
	{
		if (!*exec_env)
			ft_addtotab(exec_env, cmd[i++]);
		else
			ft_modify_variable(exec_env, cmd[i++]);
	}
	return (i);
}

int			ft_builtin_env(char **cmd)
{
	char	**sauv_env;
	char	**exec_env;
	int		ret_cmd;
	int		i;

	ret_cmd = EXIT_SUCCESS;
	if (!cmd[1] || ft_strequ(cmd[1], CMD_ENV))
		g_shell->env ? ft_puttab(g_shell->env): 0;
	else
	{
		sauv_env = ft_tabdup(g_shell->env);
		exec_env = NULL;
		i = ft_create_exec_env(cmd, &exec_env);
		ft_freetab(&g_shell->env);
		g_shell->env = exec_env;
		ret_cmd = ft_launch_cmd_env(cmd, i, exec_env);
		exec_env ? ft_freetab(&exec_env) : 0;
		g_shell->env = ft_tabdup(sauv_env);
		ft_freetab(&sauv_env);
	}
	return (ret_cmd);
}

char		*ft_get_env_variable(char **env, char *var)
{
	char	*temp;
	char	*stop;
	int		i;

	if (!env)
		return (NULL);
	i = 0;
	while (*(env + i))
	{
		temp = ft_strsub(*(env + i), 0,\
				ft_strchr(*(env + i), '=') - *(env + i));
		if (ft_strequ(temp, var))
		{
			stop = ft_strchr(*(env + i), '=');
			free(temp);
			return (ft_strsub(*(env + i), stop - *(env + i) + 1,\
						ft_strlen(stop)));
		}
		i++;
		free(temp);
	}
	return (NULL);
}
