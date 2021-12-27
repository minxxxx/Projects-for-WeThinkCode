/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pwd_ls_cd2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 20:51:46 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/14 09:32:08 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include <unistd.h>
#include <sys/param.h>
#include <sys/stat.h>

#define MSG_DONT_EXIST "No such file or directory"
#define MSG_NOT_A_DIR "Not a directory"
#define MSG_BAD_PERM "Permission denied"
#define MSG_CE "Chdir error"
#define MSG_ABOVE "Cannot go above server directory"
#define FREE1 ft_free((char*)(char*)save_pwd)
#define FREE2 (ft_free((char*)save_pwd), ft_free(tmp_pwd))
#define FREE3 (ft_free((char*)save_pwd), ft_free(tmp_pwd), ft_free(new_pwd))
#define FREE4 (ft_free(tmp_pwd), ft_free(new_pwd))

static t_bool	try_the_path_ls(char *path, int clnt)
{
	struct stat		l_s;
	int				i;

	if (lstat(path, &l_s) < 0)
		return (send_resp_to_clnt(MSG_DONT_EXIST, clnt), FALSE);
	if (!(S_ISDIR(l_s.st_mode)))
	{
		i = ft_strlen(path);
		while (path[--i] != '/')
			path[i] = '\0';
	}
	return (TRUE);
}

t_bool			is_path_valid_ls(t_env *env, char **cmd, int clnt)
{
	const char	*save_pwd = v_strjoin(env->pwd_init, env->pwd_cur);
	char		*new_pwd;
	char		*tmp_pwd;
	int			i;

	i = 0;
	while (cmd && cmd[++i])
	{
		if (cmd[i][0] == '-')
			continue ;
		tmp_pwd = v_strdup(cmd[i]);
		if (!try_the_path_ls(tmp_pwd, clnt))
			return (FREE2, FALSE);
		if (chdir(tmp_pwd))
			return (FREE2, send_resp_to_clnt(MSG_CE, clnt), FALSE);
		new_pwd = getcwd(NULL, PATH_MAX + 1);
		if (new_pwd[ft_strlen(new_pwd) - 1] != '/')
			new_pwd = v_strjoin_free(new_pwd, "/", TRUE, FALSE);
		if (chdir(save_pwd))
			return (FREE3, send_resp_to_clnt(MSG_CE, clnt), FALSE);
		if (ft_strncmp(env->pwd_init, new_pwd, ft_strlen(env->pwd_init)))
			return (FREE3, send_resp_to_clnt(MSG_ABOVE, clnt), FALSE);
		FREE4;
	}
	return (FREE1, TRUE);
}

void			transform_path(t_env *env, char **cmd, t_bool isls)
{
	int		i;

	i = 0;
	while (cmd && cmd[++i])
	{
		if (isls && cmd[i][0] == '-')
			continue ;
		if (cmd[i][0] == '/')
			cmd[i] = v_strjoin_free(env->pwd_init, cmd[i], FALSE, TRUE);
		else
		{
			if (env->pwd_cur[ft_strlen(env->pwd_cur) - 1] != '/')
				cmd[i] = v_strjoin_free("/", cmd[i], FALSE, TRUE);
			cmd[i] = v_strjoin_free(env->pwd_cur, cmd[i], FALSE, TRUE);
			cmd[i] = v_strjoin_free(env->pwd_init, cmd[i], FALSE, TRUE);
		}
	}
}
