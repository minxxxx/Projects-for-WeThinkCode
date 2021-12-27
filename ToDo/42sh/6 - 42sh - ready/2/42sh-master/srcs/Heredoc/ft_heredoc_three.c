/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-beer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 15:12:08 by rde-beer          #+#    #+#             */
/*   Updated: 2017/11/24 02:55:43 by rde-beer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

/*
 ** This deletes the file onces run
*/

void	ft_deletefile(char *file, t_all *a)
{
	pid_t	father;
	char	*path;

	path = ft_strjoin("rm ", file);
	father = fork();
	if (father > 0)
		wait(0);
	if (father == 0)
	{
		ft_execvp(path, a);
		ft_putendl("could not rm file");
		exit(0);
	}
	ft_strdel(&path);
}

/*
 ** This opens the file and writes to it
*/

void	ft_write_to_file(char **arr)
{
	pid_t	father;
	int		fd;
	int		i;

	i = -1;
	father = fork();
	if (father > 0)
		wait(0);
	if (father == 0)
	{
		close(1);
		fd = open(".$$$$$$", O_WRONLY | O_TRUNC);
		while (arr[++i] != NULL)
			ft_putendl(arr[i]);
		close(fd);
		exit(0);
	}
}

/*
 ** This takes the file and pipes it to the cmd
*/

void	ft_pipe_to_cmd(char *cmd, t_all *a)
{
	pid_t	father;
	int		fd;

	father = fork();
	if (father > 0)
		wait(0);
	if (father == 0)
	{
		close(0);
		fd = open(".$$$$$$", O_RDONLY);
		ft_execvp(cmd, a);
		ft_cmd_unknown(cmd);
		close(fd);
		exit(0);
	}
}

/*
 ** This redirects output into the given command.
*/

void	ft_direct_heredoc(char **arr, char *cmd, t_all *a)
{
	ft_createfile(".$$$$$$", a);
	ft_write_to_file(arr);
	ft_pipe_to_cmd(cmd, a);
	ft_deletefile(".$$$$$$", a);
}
