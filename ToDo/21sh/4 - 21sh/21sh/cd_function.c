/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 10:01:48 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/07 17:11:10 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "env.h"

void	ft_change_dir(char **split, t_parser **hq)
{
	int		ret;

	if (ft_array_size(split) == 1)
		ret = ft_change_dir_to_home(&(*hq));
	else if (split[1][0] == '-')
		ret = ft_change_dir3(split, &(*hq));
	else
		ret = ft_change_dir2(split, &(*hq));
	if (ret == 1)
		ft_printf("cd: no such file or directory: %s", split[1]);
	else if (ret == 2)
		ft_printf("cd: permission denied: %s", split[1]);
	else if (ret == 3)
		ft_printf("cd: not a directory: %s", split[1]);
}

int		ft_check_path_access(char *path)
{
	DIR		*temp;

	if (access(path, F_OK) == -1)
		return (1);
	if (access(path, R_OK) == -1)
		return (2);
	temp = opendir(path);
	if (temp == NULL)
		return (3);
	closedir(temp);
	return (4);
}

int		ft_change_dir2(char **split, t_parser **hq)
{
	int		ret;
	char	*oldpwd;
	char	*pwd;
	char	*newpwd;

	oldpwd = ft_get_line_myenv((*hq)->env, "OLDPWD");
	pwd = ft_get_line_myenv((*hq)->env, "PWD");
	if (split[1][0] == '/')
		newpwd = split[1];
	else if (split[1][0] == '.')
		newpwd = ft_build_path(pwd, &split[1][1]);
	else
		newpwd = ft_build_path(pwd, split[1]);
	if ((ret = ft_check_path_access(newpwd)) != 4)
		return (ret);
	chdir(newpwd);
	ft_update_cd_env(&newpwd, &oldpwd, &pwd, &(*hq));
	return (0);
}
