/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 21:42:37 by fkoehler          #+#    #+#             */
/*   Updated: 2016/09/21 16:07:05 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char	**get_paths(t_env *env_lst)
{
	int		i;
	t_env	*tmp_env;
	char	*tmp_path;
	char	**paths;

	i = 0;
	if ((!(tmp_env = get_env_ptr(env_lst, "PATH"))) ||
		(!tmp_env->val) || (ft_str_isempty(tmp_env->val)))
		return (NULL);
	paths = ft_strsplit(tmp_env->val, ':');
	while (paths[i])
	{
		tmp_path = paths[i];
		paths[i] = ft_strjoin(tmp_path, "/");
		free(tmp_path);
		i++;
	}
	return (paths);
}

char		*get_bin_path(char *cmd, t_env *env_lst)
{
	int		i;
	int		j;
	char	*bin_path;
	char	**paths;

	i = 0;
	bin_path = NULL;
	if (!(paths = get_paths(env_lst)) && exec_error(2, ""))
		return (NULL);
	while (paths[i])
	{
		bin_path = ft_strjoin(paths[i], cmd);
		if ((j = check_bin_path(bin_path, cmd)) == 0)
			break ;
		free(bin_path);
		bin_path = NULL;
		if (j == -1)
			break ;
		i++;
	}
	j == 1 ? exec_error(1, cmd) : (0);
	free_tab(paths);
	return (bin_path);
}

int			check_bin_path(char *bin_path, char *cmd)
{
	if (access(bin_path, F_OK) == -1)
		return (1);
	if (access(bin_path, X_OK) == -1)
		return (exec_error(3, cmd));
	return (0);
}

int			exec_bin(char *bin_path, char **argv, char **env)
{
	int	ret;

	ret = execve(bin_path, argv, env);
	free(bin_path);
	return (ret == -1) ? exec_error(4, "") : ret;
}
