/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 20:56:41 by fkoehler          #+#    #+#             */
/*   Updated: 2016/08/17 15:07:53 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	free_path_error_return(char *path)
{
	free(path);
	return (-1);
}

static void	put_pwd(t_env *home, char *path)
{
	int		i;

	i = 0;
	if (!home || !home->val[0])
		ft_putendl(path);
	else
	{
		while (home->val[i] && path[i] && home->val[i] == path[i])
			i++;
		if (!home->val[i])
			ft_printf("~%s\n", path + i);
		else
			ft_putendl(path);
	}
}

static int	check_path(char *path)
{
	struct stat	buf;

	if (stat(path, &buf) < 0)
	{
		if (access(path, F_OK) != 0)
			return (cd_error(4, path));
		if (access(path, X_OK) != 0)
			return (cd_error(3, path));
		return (cd_error(7, "an error occured while checking the path\n"));
	}
	if (!(S_ISDIR(buf.st_mode)))
		return (cd_error(5, path));
	if (access(path, X_OK) != 0)
		return (cd_error(3, path));
	return (0);
}

static char	*get_path_to_search(char *cmd, t_env *home, t_env *env_lst)
{
	char	*path;
	t_env	*oldpwd;

	path = NULL;
	oldpwd = NULL;
	if (!cmd)
		path = ft_strdup(home->val);
	else if (ft_strcmp(cmd, "-") == 0)
	{
		if (!(oldpwd = get_env_ptr(env_lst, "OLDPWD")) || !oldpwd->val[0])
			cd_error(1, "");
		else
			path = ft_strdup(oldpwd->val);
	}
	else if (cmd[0] == '~')
	{
		if (!(path = ft_strjoin(home->val, cmd + 1)))
			cd_error(0, "");
	}
	else
		path = ft_strdup(cmd);
	return (path);
}

int			ft_cd(char **cmd, t_env *env_lst)
{
	t_env	*home;
	char	*path;

	home = get_env_ptr(env_lst, "HOME");
	path = NULL;
	if ((!home || !home->val[0]) && (!cmd[1] || cmd[1][0] == '~'))
		return (cd_error(0, ""));
	if (cmd[1] && cmd[2])
		return (cd_error(2, ""));
	if (!(path = get_path_to_search(cmd[1], home, env_lst)))
		return (-1);
	if (check_path(path) != 0)
		return (free_path_error_return(path));
	if (chdir(path) != 0)
		return (free_path_error_return(path));
	if (cmd[1] && ft_strcmp(cmd[1], "-") == 0)
		put_pwd(home, path);
	if (set_new_pwd(env_lst) == -1)
		return (free_path_error_return(path));
	free(path);
	return (0);
}
