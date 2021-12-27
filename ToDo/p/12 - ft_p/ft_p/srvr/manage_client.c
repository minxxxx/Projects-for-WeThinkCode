/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 20:51:46 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/14 23:27:45 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include <unistd.h>
#include <sys/socket.h>

static void		received_pwd(t_env *env, char *newpwd)
{
	ft_free(env->pwd_clnt);
	env->pwd_clnt = v_strdup(newpwd);
}

static void		read_loop2(t_env *env, char **cmd, int clnt)
{
	if (ft_strequ(cmd[0], "pwd"))
		exec_pwd(env, cmd, clnt);
	else if (ft_strequ(cmd[0], "mkdir"))
		exec_mkdir(env, cmd, clnt);
	else if (ft_strequ(cmd[0], "rmdir"))
		exec_rmdir(env, cmd, clnt);
	else if (ft_strequ(cmd[0], "unlink"))
		exec_unlink(env, cmd, clnt);
}

static void		read_loop(t_env *env, int clnt)
{
	int		ret;
	char	buf[1024];
	char	**cmd;

	while ((ret = read(clnt, buf, 1023)) > 0)
	{
		buf[ret] = '\0';
		cmd = v_strsplit(buf, ' ');
		if (ft_strequ(cmd[0], "MYPWDIS"))
			received_pwd(env, cmd[1]);
		else if (ft_strequ(cmd[0], "quit") || ft_strequ(cmd[0], "exit"))
			ft_exit(NULL);
		else if (ft_strequ(cmd[0], "get"))
			exec_get(env, cmd, clnt);
		else if (ft_strequ(cmd[0], "put"))
			exec_put(env, cmd, clnt);
		else if (ft_strequ(cmd[0], "cd"))
			exec_cd(env, cmd, clnt);
		else if (ft_strequ(cmd[0], "ls"))
			exec_ls(env, cmd, clnt);
		read_loop2(env, cmd, clnt);
	}
	if (ret < 0)
		ft_exit("error: cannot read from clnt");
}

void			manage_client(t_env *env)
{
	int		clnt;
	pid_t	pid;

	while ((clnt = accept(env->sock, NULL, NULL)) != -1)
	{
		if ((pid = fork()) < 0)
			ft_exit("error: cannot fork");
		if (!pid)
		{
			read_loop(env, clnt);
			close(clnt);
		}
	}
	if (clnt == -1)
		ft_exit("error: cannot accept client");
}

void			send_resp_to_clnt(char *errmsg, int clnt)
{
	if (errmsg)
	{
		ft_putstr_fd("\033[31m[ERROR]\033[0m ", clnt);
		ft_putendl_fd(errmsg, clnt);
	}
	else
		ft_putendl_fd("\033[32m[SUCCESS]\033[0m", clnt);
	SEND_EOF(clnt);
}
