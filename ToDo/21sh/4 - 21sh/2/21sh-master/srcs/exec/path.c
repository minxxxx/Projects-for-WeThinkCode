/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 19:06:47 by sfranc            #+#    #+#             */
/*   Updated: 2017/09/15 16:04:57 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

void			ft_put_cmd_error(char *cmd, char *error)
{
	ft_putstr_fd(SHELL, 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(error, 2);
}

static int		ft_check_given_path(char *cmd, char **cmd_path)
{
	struct stat	ret_stat;

	if ((access(cmd, X_OK)) != -1)
	{
		if ((stat(cmd, &ret_stat) != -1) && S_ISDIR(ret_stat.st_mode))
		{
			ft_put_cmd_error(cmd, STR_IS_DIR);
			return (IS_DIR);
		}
		*cmd_path = ft_strdup(cmd);
		return (PATH_OK);
	}
	else if (access(cmd, F_OK) != -1)
	{
		ft_put_cmd_error(cmd, STR_PERM_DENIED);
		return (PERM_DENIED);
	}
	else
	{
		ft_put_cmd_error(cmd, STR_NO_FILE);
		return (NO_FILE);
	}
}

static int		ft_test_path(char *cmd, char **cmd_path, char **test)
{
	int	ret;

	if (access(*test, X_OK) != -1)
	{
		*cmd_path = *test;
		ret = PATH_OK;
	}
	else
	{
		ft_put_cmd_error(cmd, STR_PERM_DENIED);
		ret = PERM_DENIED;
		free(*test);
	}
	return (ret);
}

static int		ft_search_through_path(char *cmd, char **cmd_path)
{
	char	*tmp;
	char	**path;
	char	*test;
	int		ret;
	int		i;

	ret = CMD_NOT_FOUND;
	tmp = ft_get_env_variable(g_shell->env, "PATH");
	path = ft_strsplit(tmp, ':');
	i = 0;
	while (path && path[i])
	{
		test = ft_strjoin3(path[i], "/", cmd);
		if (access(test, F_OK) != -1)
		{
			ret = ft_test_path(cmd, cmd_path, &test);
			break ;
		}
		++i;
		free(test);
	}
	free(tmp);
	ft_freetab(&path);
	ret == CMD_NOT_FOUND ? ft_put_cmd_error(cmd, STR_CMD_NOT_FOUND) : 0;
	return (ret);
}

int				ft_get_path(char *cmd, char **cmd_path)
{
	if (ft_strchr(cmd, '/'))
		return (ft_check_given_path(cmd, cmd_path));
	else
	{
		if (!*cmd)
		{
			ft_put_cmd_error(cmd, STR_CMD_NOT_FOUND);
			return (CMD_NOT_FOUND);
		}
		else
			return (ft_search_through_path(cmd, cmd_path));
	}
}
