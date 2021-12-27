/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_getput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 20:51:46 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/14 22:43:08 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MSG_FEWARG "Too few arguments"
#define MSG_2RGS "Too many arguments"
#define MSG_ONLY "Please enter only a filename"
#define MSG_EEXIST	"File exists."
#define MSG_ENOENT	"No such file or directory."
#define MSG_EACCES	"Permission denied."
#define MSG_EISDIR	"Is a directory."
#define MSG_ENOTDIR	"Not a directory."
#define MSG_ELOOP	"Symbolic link loop detected."
#define MSG_OTHER	"Unexpected error."
#define MSG_ENAMETOOLONG "Filename too long"
#define FREE1(x) ft_free(x)
#define FREE2(x, y) ft_free(x), ft_free(y)
#define CLOSE1(x) close(x)
#define CLOSE2(x, y) close(x), close(y)
#define CHMOD755 (S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH)

static t_bool	is_input_valid(char **cmd, int clnt)
{
	if (!cmd[1])
		return (send_resp_to_clnt(MSG_FEWARG, clnt), FALSE);
	if (cmd[2])
		return (send_resp_to_clnt(MSG_2RGS, clnt), FALSE);
	if (ft_strchrstr(cmd[1], ".."))
		return (send_resp_to_clnt(MSG_ONLY, clnt), FALSE);
	if (cmd[1][0] == '/' || cmd[1][ft_strlen(cmd[1]) - 1] == '/')
		return (send_resp_to_clnt(MSG_ONLY, clnt), FALSE);
	return (TRUE);
}

static t_bool	open_file(char *filepath, int clnt, int *fd, t_bool issrc)
{
	struct stat		st;

	init_ft_errno();
	if (issrc)
		*fd = open(filepath, O_RDONLY);
	else
		*fd = open(filepath, O_WRONLY | O_CREAT | O_EXCL | O_APPEND, CHMOD755);
	if (*fd < 0)
		return (send_errno_to_clnt(clnt), FALSE);
	if (fstat(*fd, &st) < 0)
		return (send_errno_to_clnt(clnt), close(*fd), FALSE);
	if (S_ISDIR(st.st_mode))
		return (send_resp_to_clnt("Is a directory", clnt), close(*fd), FALSE);
	return (TRUE);
}

void			exec_get(t_env *env, char **cmd, int clnt)
{
	int		srcfd;
	int		dstfd;
	char	*srcpath;
	char	*dstpath;

	if (!is_input_valid(cmd, clnt))
		return ;
	srcpath = v_strjoin(env->pwd_init, env->pwd_cur);
	if (srcpath[ft_strlen(srcpath) - 1] != '/')
		srcpath = v_strjoin_free(srcpath, "/", TRUE, FALSE);
	srcpath = v_strjoin_free(srcpath, cmd[1], TRUE, FALSE);
	if (!open_file(srcpath, clnt, &srcfd, TRUE))
	{
		FREE1(srcpath);
		return ;
	}
	dstpath = v_strjoin(env->pwd_clnt, cmd[1]);
	if (!open_file(dstpath, clnt, &dstfd, FALSE))
	{
		FREE2(srcpath, dstpath), CLOSE1(srcfd);
		return ;
	}
	cpy_file(srcfd, dstfd, clnt);
	FREE2(srcpath, dstpath), CLOSE2(srcfd, dstfd);
}

void			exec_put(t_env *env, char **cmd, int clnt)
{
	int		srcfd;
	int		dstfd;
	char	*srcpath;
	char	*dstpath;

	if (!is_input_valid(cmd, clnt))
		return ;
	srcpath = v_strjoin(env->pwd_clnt, cmd[1]);
	if (!open_file(srcpath, clnt, &srcfd, TRUE))
	{
		FREE1(srcpath);
		return ;
	}
	dstpath = v_strjoin(env->pwd_init, env->pwd_cur);
	if (dstpath[ft_strlen(dstpath) - 1] != '/')
		dstpath = v_strjoin_free(dstpath, "/", TRUE, FALSE);
	dstpath = v_strjoin_free(dstpath, cmd[1], TRUE, FALSE);
	if (!open_file(dstpath, clnt, &dstfd, FALSE))
	{
		FREE2(srcpath, dstpath), CLOSE1(srcfd);
		return ;
	}
	cpy_file(srcfd, dstfd, clnt);
	FREE2(srcpath, dstpath), CLOSE2(srcfd, dstfd);
}

void			send_errno_to_clnt(int clnt)
{
	if (errno == EEXIST)
		send_resp_to_clnt(MSG_EEXIST, clnt);
	else if (errno == EACCES)
		send_resp_to_clnt(MSG_EACCES, clnt);
	else if (errno == ENOENT)
		send_resp_to_clnt(MSG_ENOENT, clnt);
	else if (errno == ELOOP)
		send_resp_to_clnt(MSG_ELOOP, clnt);
	else if (errno == ENOTDIR)
		send_resp_to_clnt(MSG_ENOTDIR, clnt);
	else if (errno == EISDIR)
		send_resp_to_clnt(MSG_EISDIR, clnt);
	else if (errno == ENAMETOOLONG)
		send_resp_to_clnt(MSG_ENAMETOOLONG, clnt);
	else
		send_resp_to_clnt(MSG_OTHER, clnt);
}
