/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_shell2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 22:02:23 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/14 23:23:06 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <unistd.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define GETCWD getcwd(NULL, PATH_MAX + 1)
#define WIDEAZEHOME "/Volumes/Data/nfs/zfs-student-5/users/2014/wide-aze"
#define MSG_2CMD "\033[31m[ERROR]\033[0m Too many arguments"
#define MSG_DONT_EXIST "\033[31m[ERROR]\033[0m No such file or directory"
#define MSG_NOT_A_DIR "\033[31m[ERROR]\033[0m Not a directory"
#define MSG_BAD_PERM "\033[31m[ERROR]\033[0m Permission denied"
#define MSG_CANT "\033[31m[ERROR]\033[0m Cannot exec ls"

static t_bool	is_valid_dir(char *path, t_bool iscd)
{
	struct stat		l_s;

	if (lstat(path, &l_s) < 0)
		return (ft_putendl(MSG_DONT_EXIST), FALSE);
	if (iscd && !(S_ISDIR(l_s.st_mode)))
		return (ft_putendl(MSG_NOT_A_DIR), FALSE);
	if (!(l_s.st_mode & (1 << (9 - 3))))
		return (ft_putendl(MSG_BAD_PERM), FALSE);
	return (TRUE);
}

static int		exec_lpwd(char **cmd, char *pwd)
{
	if (cmd[1])
		return (ft_putendl(MSG_2CMD), ft_free(pwd), 2);
	if (!pwd)
		return (ft_putendl("\033[31m[ERROR]\033[0m Cannot bring back pwd"), 2);
	ft_putendl(pwd), ft_putendl("\033[32m[SUCCESS]\033[0m");
	return (ft_free(pwd), 2);
}

static int		exec_lcd(t_env *env, char *pwd)
{
	if (!env->cmd[1])
		env->cmd = add_str_strtab(env->cmd, WIDEAZEHOME);
	if (env->cmd[2])
		return (ft_putendl(MSG_2CMD), 2);
	if (env->cmd[1][0] != '/')
	{
		if (pwd[ft_strlen(pwd) - 1] != '/')
			pwd = v_strjoin_free(pwd, "/", TRUE, FALSE);
		env->cmd[1] = v_strjoin_free(pwd, env->cmd[1], TRUE, TRUE);
	}
	else
		ft_free(pwd);
	if (!is_valid_dir(env->cmd[1], TRUE))
		return (2);
	if (chdir(env->cmd[1]))
		return (ft_putendl("\033[31m[ERROR]\033[0m Chdir error"), 2);
	ft_putendl("\033[32m[SUCCESS]\033[0m");
	return (2);
}

static int		exec_lls(t_env *env, char *pwd)
{
	pid_t	pid;
	char	*err_code;
	int		i;

	i = 0;
	while (env->cmd[++i])
	{
		if (env->cmd[i][0] == '-')
			continue ;
		if (env->cmd[i][0] != '/')
			env->cmd[i] = v_strjoin_free(pwd, env->cmd[i], FALSE, TRUE);
		if (!is_valid_dir(env->cmd[i], FALSE))
			return (2);
	}
	if ((pid = fork()) == -1)
		ft_exit("error: error fork");
	if (!pid)
		return (execv("/bin/ls", env->cmd), ft_putendl(MSG_CANT), 2);
	wait4(pid, &i, 0, NULL);
	if (WIFEXITED(i) && !i)
		return (ft_putendl("\033[32m[SUCCESS]\033[0m"), 2);
	err_code = v_itoa(WEXITSTATUS(i));
	ft_putstr("\033[31m[ERROR]\033[0m error code = ");
	ft_putendl(err_code), ft_free(err_code), ft_free(pwd);
	return (2);
}

int				is_cmd_valid(t_env *env)
{
	if (ft_strequ("ls", env->cmd[0]) || ft_strequ("cd", env->cmd[0])
		|| ft_strequ("get", env->cmd[0]) || ft_strequ("put", env->cmd[0])
		|| ft_strequ("pwd", env->cmd[0]) || ft_strequ("mkdir", env->cmd[0])
		|| ft_strequ("rmdir", env->cmd[0]) || ft_strequ("unlink", env->cmd[0]))
		return (1);
	if (ft_strequ("lpwd", env->cmd[0]))
		return (exec_lpwd(env->cmd, GETCWD));
	if (ft_strequ("lcd", env->cmd[0]))
		return (exec_lcd(env, GETCWD));
	if (ft_strequ("lls", env->cmd[0]))
		return (exec_lls(env, v_strjoin_free(GETCWD, "/", TRUE, FALSE)));
	return (0);
}
