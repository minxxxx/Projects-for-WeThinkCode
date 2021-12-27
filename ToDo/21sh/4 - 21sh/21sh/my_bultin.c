/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_bultin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 12:39:47 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/07 16:04:58 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "env.h"

int		ft_my_builtins_check(t_cmd **cmd)
{
	if (ft_strcmp((*cmd)->exec_name, "cd") == 0)
		return (1);
	if (ft_strcmp((*cmd)->exec_name, "env") == 0)
		return (1);
	if (ft_strcmp((*cmd)->exec_name, "setenv") == 0)
		return (1);
	if (ft_strcmp((*cmd)->exec_name, "unsetenv") == 0)
		return (1);
	if (ft_strcmp((*cmd)->exec_name, "pwd") == 0)
		return (1);
	if (ft_strcmp((*cmd)->exec_name, "exit") == 0)
		return (1);
	return (0);
}

void	ft_my_builtins(t_cmd **cmd, char **env, t_parser **hq)
{
	if (ft_strcmp((*cmd)->exec_name, "cd") == 0)
		ft_change_dir((*cmd)->argv, &(*hq));
	else if (ft_strncmp((*cmd)->exec_name, "pwd", 3) == 0)
		ft_builtin_pwd((*cmd)->argv, env);
	else if (ft_strcmp((*cmd)->exec_name, "env") == 0)
		ft_print_myenv(env);
	else if (ft_strcmp((*cmd)->exec_name, "setenv") == 0)
		ft_builtin_setenv((*cmd)->argv, &(*hq));
	else if (ft_strcmp((*cmd)->exec_name, "unsetenv") == 0)
		ft_builtin_unsetenv((*cmd)->argv, &(*hq));
	else if (ft_strcmp((*cmd)->exec_name, "exit") == 0)
		exit(1);
}

void	ft_builtin_pwd(char **argv, char **env)
{
	int		size;
	char	*line;

	line = NULL;
	size = ft_array_size(argv);
	if (size > 1)
		ft_putendl_fd("pwd: too many arguments", 2);
	line = ft_get_line_myenv(env, "PWD");
	ft_putendl(line);
}

void	ft_builtin_setenv(char **argv, t_parser **hq)
{
	if (ft_array_size(argv) != 3)
		return (ft_putendl_fd("error: too few or many arguments", 2));
	(*hq)->env = ft_add_line_myenv((*hq)->env, argv[1], argv[2]);
}

void	ft_builtin_unsetenv(char **argv, t_parser **hq)
{
	if (ft_array_size(argv) != 2)
		return (ft_putendl_fd("error: too few or many arguments", 2));
	if (ft_check_var_exist_myenv((*hq)->env, argv[1]) == 0)
		return (ft_putendl_fd("error: variable not found", 2));
	(*hq)->env = ft_remove_line_myenv((*hq)->env, argv[1]);
}
