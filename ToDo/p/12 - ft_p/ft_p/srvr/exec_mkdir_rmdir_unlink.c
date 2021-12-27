/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_mkdir_rmdir_unlink.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/14 22:48:10 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/14 23:27:55 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include <sys/stat.h>
#include <unistd.h>

#define MSG_FEWARG "Too few arguments"
#define MSG_2RGS "Too many arguments"
#define MSG_ONLY "Please enter a direct path"
#define CHMOD755 (S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH)

static t_bool	is_input_valid(char **cmd, int clnt)
{
	if (!cmd[1])
		return (send_resp_to_clnt(MSG_FEWARG, clnt), FALSE);
	if (cmd[2])
		return (send_resp_to_clnt(MSG_2RGS, clnt), FALSE);
	if (ft_strchrstr(cmd[1], ".."))
		return (send_resp_to_clnt(MSG_ONLY, clnt), FALSE);
	if (cmd[1][0] == '/')
		return (send_resp_to_clnt(MSG_ONLY, clnt), FALSE);
	return (TRUE);
}

void			exec_unlink(t_env *env, char **cmd, int clnt)
{
	char	*path;

	if (!is_input_valid(cmd, clnt))
		return ;
	path = v_strjoin(env->pwd_init, env->pwd_cur);
	if (path[ft_strlen(path) - 1] != '/')
		path = v_strjoin_free(path, "/", TRUE, FALSE);
	path = v_strjoin_free(path, cmd[1], TRUE, FALSE);
	if (unlink(path))
		send_errno_to_clnt(clnt);
	else
		send_resp_to_clnt(NULL, clnt);
	ft_free(path);
}

void			exec_mkdir(t_env *env, char **cmd, int clnt)
{
	char	*path;

	if (!is_input_valid(cmd, clnt))
		return ;
	path = v_strjoin(env->pwd_init, env->pwd_cur);
	if (path[ft_strlen(path) - 1] != '/')
		path = v_strjoin_free(path, "/", TRUE, FALSE);
	path = v_strjoin_free(path, cmd[1], TRUE, FALSE);
	if (mkdir(path, CHMOD755))
		send_errno_to_clnt(clnt);
	else
		send_resp_to_clnt(NULL, clnt);
	ft_free(path);
}

void			exec_rmdir(t_env *env, char **cmd, int clnt)
{
	char	*path;

	if (!is_input_valid(cmd, clnt))
		return ;
	path = v_strjoin(env->pwd_init, env->pwd_cur);
	if (path[ft_strlen(path) - 1] != '/')
		path = v_strjoin_free(path, "/", TRUE, FALSE);
	path = v_strjoin_free(path, cmd[1], TRUE, FALSE);
	if (rmdir(path))
		send_errno_to_clnt(clnt);
	else
		send_resp_to_clnt(NULL, clnt);
	ft_free(path);
}
