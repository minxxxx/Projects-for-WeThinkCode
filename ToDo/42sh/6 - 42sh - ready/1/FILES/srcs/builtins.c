/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <dtedgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 10:06:41 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/26 15:50:33 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh.h"

void	change_cwd(char **args, t_env **list)
{
	char	*pwd;

	pwd = NULL;
	if (args[1] == NULL || ft_strcmp(args[1], "~") == 0)
		args[1] = search_in_env("HOME", *list);
	else if (ft_strcmp(args[1], "-") == 0)
	{
		chdir(search_in_env("OLDPWD", *list));
		pwd = search_in_env("PWD", *list);
		ft_setenv("OLDPWD", pwd, list);
		ft_setenv("PWD", getcwd(pwd, 120), list);
		return ;
	}
	if (chdir(args[1]) == 0)
	{
		pwd = getcwd(pwd, 120);
		ft_setenv("OLDPWD", search_in_env("PWD", *list), list);
		ft_setenv("PWD", pwd, list);
	}
	else
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(args[1]);
	}
}

void	ft_echo(char **args, t_env *list)
{
	char	*to_print;

	to_print = ft_strjoin_array(&args[1], " ");
	to_print = ft_strtrim_nolimit(to_print, '"', "'");
	if (to_print[0] == '$')
		ft_putendl(search_in_env(&to_print[1], list));
	else
		ft_putendl(to_print);
}

int		builtin_commands(char *name, char **args, t_env **env_list)
{
	int		ret;

	ret = 0;
	if (ft_strcmp(name, "cd") == 0 && (ret = 1))
		change_cwd(args, env_list);
	else if (ft_strcmp(name, "env") == 0 && (ret = 1))
		print_env(*env_list);
	else if (ft_strcmp(name, "setenv") == 0 && (ret = 1))
		ft_setenv(args[1], args[2], env_list);
	else if (ft_strcmp(name, "unsetenv") == 0 && (ret = 1))
		ft_unsetenv(args[1], env_list);
	else if (ft_strcmp(name, "echo") == 0 && (ret = 1))
		ft_echo(args, *env_list);
	else if (ft_strcmp(name, "exit") == 0)
		ret = 1;
	if (ret == 1)
		return (1);
	return (0);
}
