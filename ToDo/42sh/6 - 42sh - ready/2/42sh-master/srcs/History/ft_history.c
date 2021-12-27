/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 15:34:44 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:56:48 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"
#define VAR int fd;char *file
#define VARR char *cmd;char	*file;char *path;int i;int fd;int num
#define FREE ft_strdel(&file);ft_strdel(&path)

/*
 ** Locates the history file
*/

char	*find_hist(t_all *a)
{
	int		find;
	char	**home;
	char	*path;

	find = 0;
	while (ft_strncmp(a->new[find], "HOME=", 5) != 0 && a->new[find] != NULL)
		find++;
	home = ft_strsplit(a->new[find], '=');
	path = ft_strdup(home[1]);
	ft_delarray(home);
	return (path);
}

/*
 ** Creates the history file when the shell first starts
*/

void	ft_createhistory(t_all *a)
{
	char	*path;
	int		fd;
	int		find;
	char	**home;

	find = 0;
	a->histnum = 0;
	while (ft_strncmp(a->new[find], "HOME=", 5) != 0 && a->new[find] != NULL)
		find++;
	home = ft_strsplit(a->new[find], '=');
	path = ft_strjoin(home[1], "/.42shell_history");
	fd = open(path, O_CREAT | O_TRUNC, 0777);
	close(fd);
	ft_strdel(&path);
	ft_delarray(home);
}

/*
 ** Adds the command to the history file
*/

void	ft_add_to_hist(char *str, t_all *a)
{
	char	**home;
	int		find;

	VAR;
	find = 0;
	a->history = ft_add_to_array(a->history, str);
	a->histnum++;
	while (ft_strncmp(a->new[find], "HOME=", 5) != 0 && a->new[find] != NULL)
		find++;
	home = ft_strsplit(a->new[find], '=');
	file = ft_strjoin(home[1], "/.42shell_history");
	fd = open(file, O_WRONLY | O_APPEND, 0777);
	ft_putendl_fd(str, fd);
	close(fd);
	ft_delarray(home);
	a->histpos = ft_arraylen(a->history);
	ft_strdel(&file);
}

/*
 ** Finds the history number in the file to execute
*/

char	*ft_exec_history(char *hist, t_all *a)
{
	VARR;
	i = 0;
	ft_memmove(hist, hist + 1, ft_strlen(hist));
	num = ft_atoi(hist);
	file = find_hist(a);
	path = ft_strjoin(file, "/.42shell_history");
	fd = open(path, O_RDWR, 0777);
	while (i < a->histnum)
	{
		get_next_line(fd, &cmd);
		if (i == num - 1)
			break ;
		i++;
		ft_strdel(&cmd);
	}
	FREE;
	close(fd);
	if (num > a->histnum)
	{
		ft_strdel(&cmd);
		return (hist);
	}
	else
		ft_strdel(&hist);
	return (cmd);
}
