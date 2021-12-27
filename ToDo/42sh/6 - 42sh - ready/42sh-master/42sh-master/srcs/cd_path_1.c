/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_path_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static void		native_full(char *path, t_env **env, char *old_pwd)
{
	if (chdir(path) == 0)
	{
		change_arg(*env, "OLDPWD", old_pwd);
		change_arg(*env, "PWD", path);
	}
}

static void		made_full(char *path, t_env **env, char *full, char *old_pwd)
{
	if (chdir(path) == 0)
	{
		change_arg(*env, "OLDPWD", old_pwd);
		change_arg(*env, "PWD", full);
	}
	ft_strdel(&full);
}

static void		just_path(char *path, t_env **env, char *old_pwd)
{
	char	*wd;

	if (chdir(path) == 0)
	{
		change_arg(*env, "OLDPWD", old_pwd);
		wd = triple_join(old_pwd, "/", path);
		change_arg(*env, "PWD", wd);
		free(wd);
	}
}

void			cd_symblink(char *path, t_env **env, t_data *data)
{
	char	*old_pwd;
	char	*full;

	old_pwd = find_var_env(data, "PWD", *env);
	full = NULL;
	if (ft_strstr(path, "..") || ft_strstr(path, "./"))
	{
		full = triple_join(old_pwd, "/", path);
		full = troncate_dots(full);
	}
	if (path[0] == '/' && !full)
		native_full(path, env, old_pwd);
	else if (full)
		made_full(path, env, full, old_pwd);
	else
		just_path(path, env, old_pwd);
	free(old_pwd);
}

void			cd_physical(char *path, t_env **env, t_data *data, t_cmd *cmd)
{
	int		ret;
	char	*buf_wd;
	char	*old_pwd;

	if ((buf_wd = (char *)mallocp(sizeof(char) * 1024)))
	{
		old_pwd = find_var_env(data, "PWD", *env);
		if ((ret = chdir(path)) == 0)
		{
			change_arg(*env, "OLDPWD", old_pwd);
			change_arg(*env, "PWD", getcwd(buf_wd, 1024));
		}
		else
			display_cd_permission(path, cmd, data);
		free(buf_wd);
		free(old_pwd);
	}
}
