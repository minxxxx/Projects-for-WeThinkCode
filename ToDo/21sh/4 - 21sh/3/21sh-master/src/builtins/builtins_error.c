/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 13:32:34 by fkoehler          #+#    #+#             */
/*   Updated: 2016/09/21 14:48:00 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		cd_error(int errnum, char *arg)
{
	int	fd;

	fd = STDERR_FILENO;
	ft_putstr_fd("cd: ", fd);
	if (errnum == 0)
		ft_putstr_fd("environment variable HOME not set or empty\n", fd);
	else if (errnum == 1)
		ft_putstr_fd("environment variable OLDPWD not set or empty\n", fd);
	else if (errnum == 2)
		ft_putstr_fd("too many arguments\n", fd);
	else if (errnum == 3 || errnum == 4 || errnum == 5 || errnum == 7)
		ft_putstr_fd(arg, fd);
	else if (errnum == 6 || errnum == 8)
		ft_putstr_fd("an error occured while ", fd);
	if (errnum == 3)
		ft_putstr_fd(" : permission denied\n", fd);
	else if (errnum == 4)
		ft_putstr_fd(" : no such file or directory\n", fd);
	else if (errnum == 5)
		ft_putstr_fd(" : not a directory\n", fd);
	else if (errnum == 6)
		ft_putstr_fd("switching the actual directory with 'chdir'\n", fd);
	else if (errnum == 8)
		ft_putstr_fd("checking the actual directory with 'getcwd'\n", fd);
	return (-1);
}

int		env_error(int errnum, int flag)
{
	int		fd;

	fd = STDERR_FILENO;
	if (errnum == 0)
	{
		ft_putstr_fd("env: illegal option -- ", fd);
		ft_putchar_fd(flag, fd);
	}
	else if (errnum == 1)
	{
		ft_putstr_fd("env: option requires an argument -- ", fd);
		ft_putchar_fd(flag, fd);
	}
	else if (errnum == 2)
		ft_putstr_fd("env: no option specified", fd);
	ft_putstr_fd("\nusage: env [-i] [-u name] [name=value] ", fd);
	ft_putstr_fd("[utility [argument(s)]]\n", fd);
	return (-1);
}

void	env_var_error(int errnum, char *cmd, char *arg)
{
	int		fd;

	fd = STDERR_FILENO;
	ft_putstr_fd(cmd, fd);
	if (errnum == 0)
		ft_putstr_fd(": command requires argument\n", fd);
	else if (errnum == 1)
	{
		ft_putstr_fd(": argument is not valid: ", fd);
		ft_putendl_fd(arg, fd);
	}
	else if (errnum == 2)
	{
		ft_putstr_fd(": no such file or directoty: ", fd);
		ft_putendl_fd(arg, fd);
	}
}

int		exit_error(int errnum, char *arg)
{
	int		fd;

	fd = STDERR_FILENO;
	if (errnum == 0)
		ft_putstr_fd("exit: too many arguments\n", fd);
	else if (errnum == 1)
	{
		ft_putstr_fd("exit: argument is not numeric: ", fd);
		ft_putendl_fd(arg, fd);
	}
	else if (errnum == 2)
	{
		ft_putstr_fd("exit: number is too long: ", fd);
		ft_putendl_fd(arg, fd);
	}
	if (arg[0])
		free(arg);
	return (1);
}
