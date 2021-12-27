/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_path_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static char		*create_chdir_path(char *path, t_env **env, t_data *data)
{
	char	*good;

	if (access(path, F_OK) == 0)
		return (ft_strdup(path));
	if ((good = concat_chdir(path, env, data, 0)))
		return (good);
	return (ft_strdup(path));
}

void			change_dir(char *path, t_env **env, t_data *data, int p)
{
	struct stat		*st;
	char			*ready;

	if (path && (st = (struct stat *)mallocp(sizeof(struct stat))))
	{
		path = create_chdir_path(path, env, data);
		if (lstat(path, st) == 0)
		{
			if (p == 0 && (S_ISLNK(st->st_mode)))
			{
				if (ft_strlen(path) > 2)
					ft_remove_endchar(path, '/');
				ready = remove_duplicate_slash(path);
				cd_symblink(ready, env, data);
				ft_strdel(&ready);
			}
			else
				cd_physical(path, env, data, data->cd_cmd);
		}
		else
			display_not_such("cd", path, data->cd_cmd, data);
		free(st);
		free(path);
	}
}

void			go_to_home_directory(t_env **env, t_data *data)
{
	char	*home;

	home = (char *)find_var_env(data, "HOME", *env);
	if (!ft_strequ(home, ""))
	{
		change_dir(home, env, data, 0);
	}
	else
	{
		data->cd_ret = 1;
		ft_putendl_fd("cd: HOME not set", 2);
	}
	free(home);
}

void			go_to_old_pwd(t_data *data, t_env **env, int p)
{
	char	*old_pwd;
	char	*tmp;

	tmp = find_var_env(data, "OLDPWD", *env);
	if (!ft_strequ(tmp, ""))
	{
		old_pwd = find_var_env(data, "OLDPWD", *env);
		if (!ft_strequ(old_pwd, ""))
		{
			change_dir(old_pwd, env, data, p);
		}
		free(old_pwd);
	}
	else
	{
		ft_putendl_fd("cd: OLDPWD not set", 2);
		data->cd_ret = 1;
	}
	free(tmp);
}
