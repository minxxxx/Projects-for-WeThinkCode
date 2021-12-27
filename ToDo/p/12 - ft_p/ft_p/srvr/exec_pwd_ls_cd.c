/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pwd_ls_cd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 20:51:46 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/14 09:32:10 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/param.h>

#define MSG_DONT_EXIST "No such file or directory"
#define MSG_NOT_A_DIR "Not a directory"
#define MSG_BAD_PERM "Permission denied"
#define MSG_CE "Chdir error"
#define MSG_ABOVE "Cannot go above server directory"
#define MSG_2ARGS "Too many arguments"
#define FREEBOTH ft_free((char*)save_pwd), ft_free((char*)new_pwd)

static t_bool	try_the_path_cd(char *path, int clnt)
{
	struct stat		l_s;

	if (lstat(path, &l_s) < 0)
		return (send_resp_to_clnt(MSG_DONT_EXIST, clnt), FALSE);
	if (!(S_ISDIR(l_s.st_mode)))
		return (send_resp_to_clnt(MSG_NOT_A_DIR, clnt), FALSE);
	if (!(l_s.st_mode & (1 << (9 - 3))))
		return (send_resp_to_clnt(MSG_BAD_PERM, clnt), FALSE);
	return (TRUE);
}

static void		update_pwd(t_env *env)
{
	char	*tmp;
	int		i;

	ft_free(env->pwd_cur);
	tmp = getcwd(NULL, PATH_MAX + 1);
	i = 0;
	while (tmp[i] == env->pwd_init[i])
		i++;
	if (!tmp[i])
		env->pwd_cur = v_strdup("/");
	else
		env->pwd_cur = v_strdup(&tmp[i]);
	ft_free(tmp);
}

void			exec_cd(t_env *env, char **cmd, int clnt)
{
	const char	*save_pwd = v_strjoin(env->pwd_init, env->pwd_cur);
	char		*new_pwd;

	if (!cmd[1])
		cmd = add_str_strtab(cmd, "/"), ft_free((char*)save_pwd);
	if (cmd[2])
	{
		send_resp_to_clnt(MSG_2ARGS, clnt), ft_free((char*)save_pwd);
		return ;
	}
	transform_path(env, cmd, FALSE);
	if (!try_the_path_cd(cmd[1], clnt))
		return ;
	if (chdir(cmd[1]))
	{
		ft_free((char*)save_pwd), send_resp_to_clnt(MSG_CE, clnt);
		return ;
	}
	new_pwd = getcwd(NULL, PATH_MAX + 1);
	if (new_pwd[ft_strlen(new_pwd) - 1] != '/')
		new_pwd = v_strjoin_free(new_pwd, "/", TRUE, FALSE);
	if (ft_strncmp(env->pwd_init, new_pwd, ft_strlen(env->pwd_init)))
		chdir(save_pwd), send_resp_to_clnt(MSG_ABOVE, clnt), FREEBOTH;
	else
		update_pwd(env), send_resp_to_clnt(NULL, clnt), FREEBOTH;
}

void			exec_pwd(t_env *env, char **cmd, int clnt)
{
	if (cmd[1])
		send_resp_to_clnt(MSG_2ARGS, clnt);
	else
		ft_putendl_fd(env->pwd_cur, clnt), send_resp_to_clnt(NULL, clnt);
}

void			exec_ls(t_env *env, char **cmd, int clnt)
{
	pid_t	pid;
	int		stat;
	char	*err_code;

	transform_path(env, cmd, TRUE);
	if (!is_path_valid_ls(env, cmd, clnt))
		return ;
	if ((pid = fork()) == -1)
		ft_exit("error: error fork");
	if (!pid)
	{
		dup2(clnt, 1), dup2(clnt, 2), execv("/bin/ls", cmd);
		send_resp_to_clnt("cannot exec ls", clnt);
		return ;
	}
	wait4(pid, &stat, 0, NULL);
	if (WIFEXITED(stat) && !stat)
		send_resp_to_clnt(NULL, clnt);
	else
	{
		err_code = v_itoa(WEXITSTATUS(stat));
		err_code = v_strjoin_free("error code = ", err_code, FALSE, TRUE);
		send_resp_to_clnt(err_code, clnt), ft_free(err_code);
	}
}
