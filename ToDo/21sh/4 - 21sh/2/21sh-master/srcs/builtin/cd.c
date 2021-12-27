/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 10:29:33 by sfranc            #+#    #+#             */
/*   Updated: 2017/10/06 14:42:12 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

static void	ft_put_cd_error(char *dir, int err)
{
	char *tmp;

	tmp = ft_strjoin("cd: ", dir);
	if (err == EACCES)
		ft_put_cmd_error(tmp, STR_PERM_DENIED);
	else if (err == ENOENT)
		ft_put_cmd_error(tmp, STR_NO_FILE);
	else if (err == ENOTDIR)
		ft_put_cmd_error(tmp, STR_NOT_DIR);
	free(tmp);
}

static void	ft_modify_env(char *key, char *name)
{
	char	*var;

	var = ft_strjoin(key, name);
	ft_modify_variable(&g_shell->env, var);
	free(var);
}

static int	ft_move_to_dest(char *dest)
{
	char	*old_pwd;
	char	*pwd;

	errno = 0;
	old_pwd = getcwd(NULL, 0);
	if ((chdir(dest)) != -1)
	{
		pwd = getcwd(NULL, 0);
		pwd ? ft_modify_env("PWD=", pwd) : 0;
		old_pwd ? ft_modify_env("OLDPWD=", old_pwd) : 0;
		free(old_pwd);
		free(pwd);
		free(dest);
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_put_cd_error(dest, errno);
		free(old_pwd);
		free(dest);
		return (EXIT_FAILURE);
	}
}

int			ft_builtin_cd(char **cmd)
{
	char	*dest;

	if (!cmd[1])
	{
		if (!(dest = ft_get_env_variable(g_shell->env, "HOME")))
		{
			ft_put_cmd_error(CMD_CD, STR_HOME);
			return (EXIT_FAILURE);
		}
	}
	else if (ft_strequ(cmd[1], "-"))
	{
		if (!(dest = ft_get_env_variable(g_shell->env, "OLDPWD")))
		{
			ft_put_cmd_error(CMD_CD, STR_OLDPWD);
			return (EXIT_FAILURE);
		}
		ft_putendl(dest);
	}
	else
		dest = ft_strdup(cmd[1]);
	return (ft_move_to_dest(dest));
}
